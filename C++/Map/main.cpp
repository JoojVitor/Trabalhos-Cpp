#include <iostream>
#include "mapavl.cpp"
using namespace std;

int main()
{
    MapAVL im;
    thing a,aux;

    for (int i=0; i<10; i++) {
        a.key = i;
        im.Push(&a);
    }
    im.Remove(&im.root,8,&aux);
    //cout<< aux.key <<endl;
}
