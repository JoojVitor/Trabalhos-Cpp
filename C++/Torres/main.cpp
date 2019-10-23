//esse mesmo v.02
#include <iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

static int stop=0;

bool insereTorre(ficha *aux, stackVector *T){
    stop = 0;
    int tw = aux->in;

    loop:
    if(tw > 6){
        tw = 1;
    }
    if(aux->ch == 'P'){
        if(T[tw].IsEmpty()){
            cout<< "Torre " << tw << " vazia, jogada valida\n";
        }else{
            T[tw].Pop(aux);
                cout<< "Ficha " << aux->in << " retirada\n";
        }
    }else{
            if(!T[tw].IsFull()){
                T[tw].Push(*aux);
            cout<< "Ficha " << aux->in << " inserida\n";
        }else{
            if(stop >= 7)
                return false;
            stop++;
            tw++;
            goto loop;
        }
    }
    return true;
}

int main()
{
    char SN = 'S';
    while(SN == 'S' or SN == 's') {

        stop = 0;
        stackVector T[7] = {0};
        Queue J[5];
        ficha F,aux;

        int n, j;
        char c;
        cout<< "Insira as fichas: ";
        for(int i=0; i < 52; i++){
            cin>> j >> c >> n;
            if(c == 'P'){
                F.setFicha(c,n,j);
                J[j].Enqueue(&F);
            }else{

                switch(j){
                case 1: F.setFicha('A',n,j);
                        J[j].Enqueue(&F);
                        break;
                case 2: F.setFicha('V',n,j);
                        J[j].Enqueue(&F);
                        break;
                case 3: F.setFicha('R',n,j);
                        J[j].Enqueue(&F);
                        break;
                case 4: F.setFicha('B',n,j);
                        J[j].Enqueue(&F);
                        break;
                }
            }
        }

        system("cls");

        int cont = 1, rodada = 1;
        cout<< "\n----------- Rodada " << rodada <<" -----------\n";
        while(stop < 7){
            if(cont == 5){
                rodada++;
                cout<< "\n----------- Rodada " << rodada <<" -----------\n";
                cont = 1;
            }
            cout<< "Turno Jogador "<< cont << ": ";

            J[cont].Dequeue(&F);
            insereTorre(&F,T);
            cont++;
        }
            cout<< "\n\n";
            int t[7];
            for(int i=1; i<=6; i++) {
                for(int j=1; j<=i; j++) {
                    T[i].Pop(&aux);
                }
                t[i] = aux.jg;
            }

            cout<< "============================================================\n\nVencedor(es): ";
            aux.retVencedor(t);
            cout<< "\n\n============================================================\n\n";

            for(int i=1; i<=6; i++){
                T[i].imprime();cout << '\n';
            }
            system("pause");
            system("cls");
            cout<< "Continuar? (S/N): ";
            cin>> SN;
    }
}
