#include "matriz.cpp"

int main(){

    char arr[9] = {'a','b','c','d','e','f','g','h','i'};
    double arr2[9] = {1.1,2.1,3.5,4.2,5.6,6.8,7.3,8.1,9.5};
    int pos = 0;

    int linha, coluna;
    linha = 3;
    coluna = 3;

    Matriz<char> *matA = new Matriz<char>(linha,coluna);
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matA-> setElemento(i, j, arr[pos]);
            pos++;
        }
    }
    matA->imprimeMatriz();

    linha = 3;
    coluna = 3;
    pos = 0;
    Matriz<double> *matB = new Matriz<double>(linha,coluna);
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matB-> setElemento(i, j, arr2[pos]);
            pos++;
        }
    }
    matB->imprimeMatriz();
}
