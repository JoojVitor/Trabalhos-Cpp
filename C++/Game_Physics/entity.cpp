#include "entity.h"

entity::entity()
{
    ps.row = ps.col = dano = hp = 0;
}

void entity::setName(std::string name){
    nome = name;
}


void entity::setTipo(std::string type){
    tipo = type;
}

void entity::setPos(int i, int j){
    ps.row = i;
    ps.col = j;
}

void entity::setDano(int dam){
    dano = dam;
}

void entity::setHp(int HP){
    hp = HP;
}

void entity::getPos(int *i, int *j){
    *i = ps.row;
    *j = ps.col;
}

std::string entity::getName(){
    return nome;
}

std::string entity::getTipo(){
    return tipo;
}

int entity::getDano(){
    return dano;
}

int entity::getHp(){
    return hp;
}
