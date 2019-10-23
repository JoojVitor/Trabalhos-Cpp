#include "matriz.h"

Matriz::Matriz(int linhas, int colunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    ptMatriz(0)
{
    ptMatriz = new int[linhas*colunas];
    quantidadeDeLinhas = linhas;
    quantidadeDeColunas = colunas;
}

int Matriz::getElemento(int linha, int coluna)const{
    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

void Matriz::setElemento(int linha, int coluna, int elemento){
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
}

void Matriz::imprimeMatriz(){
    cout << "\n";
    for(int i = 0; i < quantidadeDeLinhas; i++){
        for(int j = 0; j < quantidadeDeColunas; j++){
            cout << getElemento(i, j);
            cout << "  ";
        }
        cout << "\n";
    }
}

Matriz *Matriz::operator +(Matriz const * const mat){
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas()){
        cout << "Matrizes de tamanhos diferentes nao podem ser adicionadas";
        return 0;
    }
    else{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) + mat->getElemento(linha,coluna);
                aux->setElemento(linha,coluna,valor);
            }
        }
        return aux;
    }
}

Matriz *Matriz::operator -(const Matriz *const mat){
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas()){
        cout << "Matrizes de tamanhos diferentes nao podem ser subtraidas";
        return 0;
    }
    else{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) - mat->getElemento(linha,coluna);
                aux->setElemento(linha,coluna,valor);
            }
        }
        return aux;
    }
}

Matriz *Matriz::operator *(int esc){
     Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
     for(int linha=0; linha<quantidadeDeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) * esc;
                aux->setElemento(linha,coluna,valor);
        }
     }
        return aux;
}

Matriz *Matriz::operator *(const Matriz *const mat){
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas()){
        cout << "Matrizes de tamanhos diferentes nao podem ser multiplicadas";
        return 0;
    }
    else{
        int AUX = 0;
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                for(int x = 0; x<quantidadeDeLinhas; x++){
                    int valor = this->getElemento(linha,x) * mat->getElemento(x,coluna);
                    AUX += valor;
                }
                aux->setElemento(linha,coluna,AUX);
                AUX = 0;
            }
        }
        return aux;
    }
}

void Matriz::operator =(int n){
    quantidadeDeLinhas = n;
    quantidadeDeColunas = n;
}

ostream Matriz::operator<<(ostream &out){
    cout << "\n";
    for(int i = 0; i < quantidadeDeLinhas; i++){
        for(int j = 0; j < quantidadeDeColunas; j++){
            cout << getElemento(i, j);
            cout << "  ";
        }
        cout << "\n";
    }
    return out;
}

istream &Matriz::operator>>(istream &in){
    int linha,coluna,elemento;
    cin>> linha;
    cin>> coluna;
    cin>> elemento;
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
    return in;
}
