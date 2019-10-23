#ifndef FORCA_H
#define FORCA_H
#include <iostream>
#include <QString>

struct stats
{
    QString palavra;
    QString palavraX;
    QString player;
    int minutos;
    int segundos;
};

class forca
{
public:
    forca();
    int livesCount();
    QString secretWord(QString);
    QString getString();
private:
    QString palavra;
    QString palavraX;
    QString player;
    int vidas;
    int minutos;
    int segundos;
};

#endif // FORCA_H
