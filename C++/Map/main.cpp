#include <iostream>
#include "mapavl.cpp"
using namespace std;

int main(){

    MapAVL<int> M;
    Thing<int> aux;
    aux.key = 1;
    M.Push(&aux);

}
