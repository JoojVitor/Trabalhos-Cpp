#include <iostream>
#include <math.h>
using namespace std;

void separa(double N, int *Int, double *Dec){
    *Int = N;
    *Dec = (N - *Int);
}

int retInt(double n){
    return n;
}

double retDec(double n){
    int aux;
    aux = n;
    return n - aux;
}

int main()
{
    double N, Dec;
    int Int, aux,rep;

    cout<<fixed;
    cout.precision(1);
    cin>> N;
    aux = N;
    separa(N,&Int,&Dec);
    cout<< "\tx" << Int << "\tint\n";

    if(N > 2.2){
        rep = ceil(retDec(N)*10);
    }else{
        rep = (retDec(N)*10);
    }

    if(rep%2 == 0){
        for(int i=0; i < 4 ; i++){
            cout<< Dec << "\t" << Dec*aux << "\t" << retInt(Dec*aux) <<endl;
            Dec *= aux;
            N = Dec;
            separa(N,&Int,&Dec);
        }
    }else{
        for(int i=0; i < 5 ; i++){
            cout<< Dec << "\t" << Dec*aux << "\t" << retInt(Dec*aux) <<endl;
            Dec *= aux;
            N = Dec;
            separa(N,&Int,&Dec);
        }
    }
}

