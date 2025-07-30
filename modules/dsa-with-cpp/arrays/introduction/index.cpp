/**
 * Introduction to Arrays in C
 * 1. Arrays are a collection of elements of the same data type. We can use indexes to access an element in the array.
 * 2. Static Arrays means an array where the size is determined at compile team. Dynamic Arrays are arrays that are created during runtime. DA are only possible in CPP.
 * 3. Once an array of a particular size is created, it cannot be resized. The variable holding the array is always a pointer.
 * 4. Stack Arrays cannot be resized, but heap arrays can by some hack. We should first create a new array of a bigger size and then copy the content of the old array to the new array. The reason resizing is not allowed, is that we DO not know if the location is free or not.
 */

#include<iostream>
using namespace std;

void delcareArrays() {
    int A[5]; //All values will be garbage as of now.
    int B[5] = {1, 2, 3, 4, 5}; //All values are set at runtime.
    int C[5] = {2, 4}; // Remainging elements will be 0 NOT garbage.
    int D[] = {1, 2, 3, 4, 5, 6}; //Array of size 6.
}

int declareDynamicArray() {
    int n;
    cin >> n;
    int B[n];

    for(int i = 0; i < n; i++) {
        B[i] = i + 1;
    }

    for(int i = 0; i < n; i++) {
        cout << B[i] << endl;
    }

    return n;
}

int * declareDynamicArrayInHeap(int n) {
    int *p;
    p = new int[n];

    p[n - 1] = 1;

    return p;
}

int main() {
    int A[4] = {1, 2, 3, 4};
    int n = declareDynamicArray();

    int *p = declareDynamicArrayInHeap(n);
    cout << n << endl;
    cout << p[n - 1] << endl;
    cout << A << p << endl;
}
