#include "entity.h"

entity::entity()
{
    id.nid = id.row = id.col = dano = hp = 0;
    tipo = "null";
}

void entity::setName(std::string name){
    nome = name;
}


void entity::setTipo(std::string type){
    tipo = type;
}

void entity::setPos(int i, int j){
    id.row = i;
    id.col = j;
}

void entity::setDano(int dam){
    dano = dam;
}

void entity::setHp(int HP){
    hp = HP;
}

void entity::getPos(int *i, int *j){
    *i = id.row;
    *j = id.col;
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
