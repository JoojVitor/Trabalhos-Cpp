#include "matriz.cpp"

int main(){

    int arr[9] = {1,4,5,2,6,8,3,7,5};
    int arr2[9] = {1,2,3,4,5,6,7,8,9};
    int pos = 0;

    int linha, coluna;
    linha = 3;
    coluna = 3;

    cout<< "MATRIZ A:\n\n";
    Matriz *matA = new Matriz(linha,coluna);
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matA-> setElemento(i, j, arr[pos]);
            pos++;
        }
    }
    matA->imprimeMatriz();

    cout<< "\n\n\nMATRIZ B:\n\n";
    linha = 3;
    coluna = 3;
    pos = 0;
    Matriz *matB = new Matriz(linha,coluna);
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matB-> setElemento(i, j, arr2[pos]);
            pos++;
        }
    }
    matB->imprimeMatriz();

    cout<< "\n\nSOMA:\n";

    Matriz *matC = 0;
    matC = (*matA) + matB;
    matC->imprimeMatriz();

    cout<< "\n\nSUBTRACAO:\n";

    matC = (*matA) - matB;
    matC->imprimeMatriz();

    cout<< "\n\nMULTIPLICACAO:\n";

    matC = (*matA) * matB;
    matC->imprimeMatriz();

    cout<< "\n\nMULTIPLICACAO: \nDigite o escalar:";

    int esc;
    cin>> esc;
    matC = (*matA) * esc;
    matC->imprimeMatriz();

    cout<< "\nATRIBUICAO: A = B\n";

    matA = matB;
    matA->imprimeMatriz();

    cout<< "\nOPERADOR <<:\nMATRIZ A:\n\n";
    cout<< matA;
    cout<< "\n\nMATRIZ B:\n\n";
    cout<< matB;


}

