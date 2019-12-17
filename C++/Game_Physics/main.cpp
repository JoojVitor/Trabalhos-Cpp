#include <iostream>
#include <locale.h>
#include "mapavl.cpp"
#include "entity.h"
using namespace std;

bool control(){
    return true;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    MapAVL data;
    pair<pos,entity> x, aux;
    pos p;
    int N;

    cout<< "Digite o número de jogadores: ";
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
        p.setPosition(l,c);
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

    int auxl, auxc;
    cout<< "Digite os limites do mapa: ";
    cin>> auxl >> auxc;
    entity mapa[auxl][auxc];

    for(int i=0; i<=N; i++){
        E[i].getPos(&l,&c);
        mapa[l][c] = E[i];
    }

    for(int i=0; i<auxl; i++){
        for(int j=0; j<auxc; j++){
            if(mapa[i][j].getTipo() == "Jogador"){
                cout<< 'X';
            }else{
                cout<< '-';
            }
            cout<< "\t";
        }
        cout<< "\n";
    }
}
