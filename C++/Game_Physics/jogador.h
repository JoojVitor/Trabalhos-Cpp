#ifndef JOGADOR_H
#define JOGADOR_H

class pos{
public:
    int row;
    int col;
};

class jogador{
private:
    pos ps;
    int dano;
    int hp;
public:
    jogador();
    void setPos(int i, int j);
    void setDano(int dam);
    void setHp(int HP);
    void getPos(int *i, int *j);
    int getDano();
    int getHp();
};

#endif // JOGADOR_H
