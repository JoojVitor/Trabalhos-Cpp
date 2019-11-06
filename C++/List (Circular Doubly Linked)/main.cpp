#include <iostream>
#include "dclist.cpp"
using namespace std;

int main(){
    DCList<int> l;
    int i, aux;
    for (i = 0; i < 10; i++) {
        l.Push(&i);
    }
    l.Pop(&aux,9);
    cout<< aux;
}
