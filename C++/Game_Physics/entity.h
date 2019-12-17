#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>

class pos{
public:
    int row;
    int col;
    void setPosition(int r, int c){row = r; col = c;}
};

class entity{
private:
    std::string nome;
    std::string tipo;
    pos ps;
    int dano;
    int hp;
public:
    entity();
    void setName(std::string);
    void setTipo(std::string);
    void setPos(int,int);
    void setDano(int);
    void setHp(int);
    void getPos(int*,int*);
    std::string getName();
    std::string getTipo();
    int getDano();
    int getHp();
};

#endif // ENTITY_H
