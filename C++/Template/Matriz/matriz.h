#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>
using namespace std;

template <typename T>
class Matriz
{
private:
    int quantidadeDeLinhas;
    int quantidadeDeColunas;
    T *ptMatriz;

public:
    Matriz(int linhas, int colunas);
    ~Matriz(){if(ptMatriz)delete[] ptMatriz;}
    int getQuantidadeDeLinhas()const{return quantidadeDeLinhas;}
    int getQuantidadeDeColunas()const{return quantidadeDeColunas;}
    T getElemento(int linha, int coluna)const;
    void setElemento(int linha, int coluna, T elemento);
    void imprimeMatriz();
    Matriz* operator +(Matriz const * const mat);
};
#endif // MATRIZ_H