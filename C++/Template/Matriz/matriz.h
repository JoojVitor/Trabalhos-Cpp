#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>
using namespace std;

class Matriz
{
private:
    int quantidadeDeLinhas;
    int quantidadeDeColunas;
    int *ptMatriz;

public:
    Matriz(int linhas, int colunas);
    ~Matriz(){if(ptMatriz)delete[] ptMatriz;}
    int getQuantidadeDeLinhas()const{return quantidadeDeLinhas;}
    int getQuantidadeDeColunas()const{return quantidadeDeColunas;}
    int getElemento(int linha, int coluna)const;
    void setElemento(int linha, int coluna, int elemento);
    void imprimeMatriz();
    Matriz * operator +(Matriz const * const mat);
    Matriz * operator -(Matriz const * const mat);
    Matriz * operator *(Matriz const * const mat);
    Matriz * operator *(int esc);
    void operator =(int n);
    ostream operator <<(ostream&);
    istream operator >>(istream&);
};
#endif // MATRIZ_H
