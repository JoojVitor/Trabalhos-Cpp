#include "entity.h"

entity::entity()
{
    id.act = 5;
    id.nid = id.row = id.col = dano = hp = 0;
    tipo = "null";
}

void entity::setName(std::string name){
    nome = name;
}

void entity::resetAct(){
   id.act = 5;
}

void entity::setID(int Id){
    id.nid = Id;
}

ID entity::getID(){
    return id;
}

bool entity::subAct(char move){
    if(id.act > 0){
        if(move == 'M'){
            id.act--;
            return true;
        }
        if(move == 'A'){
            id.act--;
            return true;
        }
        if(move == 'C'){
            if((id.act - 4) >= 0){
                id.act -= 4;
                return true;
            }
            std::cout<< "Sem pontos\n";
            return false;
        }
        if(move == 'D'){
            if((id.act - 3) >= 0){
                id.act -= 3;
                return true;
            }
            std::cout<< "Sem pontos\n";
            return false;
        }
    }
    std::cout<< "Sem pontos\n";
    return false;
}

int entity::getAct(){
    return id.act;
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
