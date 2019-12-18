#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>

class ID{
public:
    int nid;
    int row;
    int col;
    int act;
    void setID(int id, int r, int c){act = 5; nid = id; row = r; col = c;}
};

class entity{
private:
    std::string nome;
    std::string tipo;
    ID id;
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
    void setID(int);
    void resetAct();
    std::string getName();
    std::string getTipo();
    int getDano();
    int getHp();
    ID getID();
    bool subAct(char);
    int getAct();
};

#endif // ENTITY_H
