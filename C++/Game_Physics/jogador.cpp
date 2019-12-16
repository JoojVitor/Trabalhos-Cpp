#include "jogador.h"

jogador::jogador()
{
    ps.row = ps.col = dano = hp = 0;
}

void jogador::setPos(int i, int j){
    ps.row = i; ps.col = j;
}

void jogador::setDano(int dam){
    dano = dam;
}

void jogador::setHp(int HP){
    hp = HP;
}

void jogador::getPos(int *i, int *j){
    i = &ps.row;
    j = & ps.col;
}

int jogador::getDano(){
    return dano;
}

int jogador::getHp(){
    return hp;
}

