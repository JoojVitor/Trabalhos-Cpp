#include "matriz.h"

template <typename T>
Matriz<T>::Matriz(int linhas, int colunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    ptMatriz(0)
{
    ptMatriz = new T[linhas*colunas];
    quantidadeDeLinhas = linhas;
    quantidadeDeColunas = colunas;
}

template <typename T>
T Matriz<T>::getElemento(int linha, int coluna)const{
    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

template <typename T>
void Matriz<T>::setElemento(int linha, int coluna, T elemento){
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
}

template <typename T>
void Matriz<T>::imprimeMatriz(){
    cout << "\n";
    for(int i = 0; i < quantidadeDeLinhas; i++){
        for(int j = 0; j < quantidadeDeColunas; j++){
            cout << getElemento(i, j);
            cout << "  ";
        }
        cout << "\n";
    }
}