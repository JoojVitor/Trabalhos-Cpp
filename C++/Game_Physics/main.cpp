#include <iostream>
#include <locale.h>
#include "mapavl.cpp"
#include "entity.h"
using namespace std;

static MapAVL data;

bool control(char cmd, int dir, int *l, int *c){
    if(cmd == 'M'){
        switch(dir){
            case 4:
            if(*c < 0){
                c--;
                l++;
            }else{
                cout<< "Movimento impossivel";
            }
            break;
        }
    }
    return false;
}

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
    p.setID(2,3,3);
    cout<< data.Pop(p,&x);

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
