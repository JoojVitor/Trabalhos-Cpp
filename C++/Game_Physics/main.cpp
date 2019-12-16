#include <iostream>
#include "mapavl.h"
#include "jogador.h"
using namespace std;

bool control(){

}

int main(){
    MapAVL<jogador> data;
    int N;
    cout<< "Digite o numero de jogadores: ";
    cin>> N;
    //system("clear");
    system("cls");
    jogador P[N+1];
    int l,c,h,d;
    for(int i=1; i<=N; i++){
        cout<< "Digite posição inicial do jogador " << i << " :";
        cin>> l >> c;
        P[i].setPos(l,c);
        cout<< "Digite o HP e Dano: ";
        cin>> h >> d;
        P[i].setHp(h);
        P[i].setDano(d);
    }
}
