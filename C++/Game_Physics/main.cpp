#include <iostream>
#include <locale.h>
#include "mapavl.cpp"
#include "entity.h"
using namespace std;

static MapAVL data;

void imprimeMatriz(int auxl, int auxc, entity **mapa){
    cout<<endl;
    for(int i=0; i<auxl; i++){
        for(int j=0; j<auxc; j++){
            if(mapa[i][j].getTipo() == "Jogador"){
                cout<< 'X';
            }else{
                if(mapa[i][j].getTipo() == "Objeto"){
                    cout<< '0';
                }else{
                    cout<< '-';
                }
            }
            cout<< "\t";
        }
        cout<< "\n";
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    pair<ID,entity> x, aux;
    ID p;
    int N;

    cout<< "Digite o numero de jogadores: ";
    cin>> N;

    //system("clear");
    system("cls");

    entity E[N+1];

    int l,c,h,d;

    for(int i=1; i<=N; i++){
        E[i].setName("Jogador " + to_string(i));
        E[i].setTipo("Jogador");
        cout<< "Digite posicao inicial do jogador " << i << " :";
        cin>> l >> c;
        p.setID(i,l,c);
        E[i].setPos(l,c);
        cout<< "Digite o HP: ";
        cin>> h;
        E[i].setHp(h);
        cout<< "Digite o Dano: ";
        cin >> d;
        E[i].setDano(d);
        E[i].setID(i);

        x.first = p;
        x.second = E[i];
        data.Push(&x);
    }

    cout<< "Digite os limites do mapa: ";
    cin>> l >> c;
    const int auxl = l, auxc = c;
    entity mapa[auxl][auxc];

    for(int i=0; i<=N; i++){
        E[i].getPos(&l,&c);
        realoc:
        if(l > auxl-1 or c > auxc-1){
            cout<< E[i].getName() << " excede os limites do mapa. Digite outra posicao: ";
            cin>> l >> c;
            E[i].setPos(l,c);
            goto realoc;
        }else{
            if(mapa[l][c].getTipo() == "Jogador"){
                cout<< "Posicao ocupada pelo " << mapa[l][c].getName() << ". Digite outra posicao: ";
                cin>> l >> c;
                E[i].setPos(l,c);
                goto realoc;
            }else{
                mapa[l][c] = E[i];
            }
        }
    }

    l = c = 0;
    int lim = (auxl * auxc) - N;
    int cont = 0;
    entity O[lim];
    cout<< "Digite os objetos do mapa: ";
    cin>> l >> c;
    while(l > -1 and c > -1){
        if(l > auxl-1 or c > auxc-1){
            cout<< "\nExcede os limites do mapa!\n";
        }else{
                if(mapa[l][c].getTipo() == "Jogador" or mapa[l][c].getTipo() == "Objeto"){
                    cout<< "\nPosicao [" << l << "][" << c << "] ja esta ocupada!\n";
            }else{
                O[cont].setTipo("Objeto");
                O[cont].setName("Objeto");
                O[cont].setPos(l,c);
                O[cont].setID(cont+(N+1));
                p.setID(cont+(N+1),l,c);
                x.first = p;
                x.second = O[cont];
                data.Push(&x);
                mapa[l][c] = O[cont];
                cont++;
            }
        }
        cin>> l >> c;
    }

    //teste de busca = OK;
    //p.setID(2,3,3);
    //cout<< data.Pop(p,&x);

    cout<<endl;
    for(int i=0; i<auxl; i++){
        for(int j=0; j<auxc; j++){
            if(mapa[i][j].getTipo() == "Jogador"){
                cout<< 'X';
            }else{
                if(mapa[i][j].getTipo() == "Objeto"){
                    cout<< '0';
                }else{
                    cout<< '-';
                }
            }
            cout<< "\t";
        }
        cout<< "\n";
    }

    //controle
    char J;
    int K, turn = N;
    int lin, col;
    cout<< "Jogadas: ";
    cin>> J >> K;
    while(J != 'F' and K != 0){
        switch(K){
            case 4:
            if(E[turn].subAct('M')){
                E[turn].getPos(&lin,&col);
                if(col > 0){
                    if(mapa[lin][col-1].getTipo() != "Objeto"){
                        if(mapa[lin][col-1].getTipo() != "Jogador"){
                            mapa[lin][col].setTipo("null");
                            data.Pop(E[turn].getID(),&x);
                            E[turn].setPos(lin,col-1);
                            p.setID(E[turn].getID().nid,lin,col-1);
                            x.first = p;
                            x.second = E[turn];
                            mapa[lin][col-1] = E[turn];
                            data.Push(&x);
                        }
                    }
                }
                cout<< E[turn].getName() << ":(" << lin << "," << col << ") ";
            }
            break;
        }
        cin>> J >> K;
    }
    cout<<endl;
    for(int i=0; i<auxl; i++){
        for(int j=0; j<auxc; j++){
            if(mapa[i][j].getTipo() == "Jogador"){
                cout<< 'X';
            }else{
                if(mapa[i][j].getTipo() == "Objeto"){
                    cout<< '0';
                }else{
                    cout<< '-';
                }
            }
            cout<< "\t";
        }
        cout<< "\n";
    }
}

/*2
0 0 21 5
5 5 15 7
6 6
1 0 0 1 3 1 5 1 1 2 4 2 2 3 2 4 4 4 1 5 -1 -1

6
1 1 1 1
1 2 1 1
3 3 1 1
3 2 1 1
1 3 1 1
1 0 1 1
5 5
2 2 -1 -1

1
3 3 1 1
5 5
-1 -1
*/
