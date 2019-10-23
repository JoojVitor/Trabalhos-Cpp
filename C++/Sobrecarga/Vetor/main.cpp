#include <iostream>
#include "vetor.cpp"

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);
    a.print();

    float arr2[5] = {1.5, 2.3, 3.4, 4.0, 5.9};
    Array<float> a2(arr2, 5);
    a2.print();
    return 0;
}
