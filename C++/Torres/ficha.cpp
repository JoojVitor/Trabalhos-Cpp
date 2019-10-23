//esse mesmo v.02
#include "ficha.h"
#include <iostream>
using namespace std;

void ficha::setFicha(char cor, int i, int j){
    in = i;
    ch = cor;
    jg = j;
}

void ficha::retVencedor(int *t){
    int j1=0,j2=0,j3=0,j4=0;
    for(int i=1; i<=6; i++){
        switch(t[i]){
            case 1:
                j1++;
                break;
            case 2:
                j2++;
                break;
            case 3:
                j3++;
                break;
            case 4:
                j4++;
                break;
        }
    }

    if(j1 >= j2 and j1 >= j3 and j1 >= j4){
        cout<< "Jogador 1 ";
    }
    if(j2 >= j1 and j2 >= j3 and j2 >= j4){
        cout<< "Jogador 2 ";
    }
    if(j3 >= j1 and j3 >= j2 and j3 >= j4){
        cout<< "Jogador 3 ";
    }
    if(j4 >= j1 and j4 >= j2 and j4 >= j3){
        cout<< "Jogador 4 ";
    }
}

