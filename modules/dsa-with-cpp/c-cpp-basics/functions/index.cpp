/**
 * Functions:
 * 1. Its a piece of code that performs a specific task. It is a group of related instructions.
 * 2. Programming with functions is called modular programming. Functions improve reusability.
 * 3. There are 3 ways that we can pass parameters to a function.
 *  - Pass by value: When parameters are passed by values, the function parameters are copied into the stack frame of the function. When we do not want to modify the parameters, we should use pass by value.
 *  - Pass by Address: Instead of passing the value of a specific variable of a function, we can pass the pointer to that variable and then the calling function can modify the pointewr value.
 *  - Pass By reference: Instead of passing the value, we pass the reference. It should be used carefully. The code is actually copied where the function is being called.
 * 4. Anything available on the heap can be made available through pointers.
 */
#include <cstdlib>
#include<iostream>
using namespace std;

void passByValueSwap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void passByAddressSwap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void passByReferenceSwap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void mixPassSwap(int *x, int y) {
    int *temp = x;
    *x = y;
    y = *temp;
}

//Whenever we pass an array, we are passing the pointer to the array to the function.
void passArrayToFunc(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
}

int * returnArrayFromFunc(int n) {
    int *P;

    P = (int*)(malloc(n * sizeof(int)));
    P[0] = 15;
    P[1] = 10;

    return P;
}

struct Rectangle {
    int length;
    int breadth;
};

int passByValueStruct(struct Rectangle r) {
    return r.length * r.breadth;
}

void passByReferenceStruct(struct Rectangle *r) {
    r->length = 23;
}

struct Test {
    int scores[5];
};

int main() {
    int a = 2;
    int b = 3;

    passByValueSwap(a, b);
    cout << a << " " << b << endl;

    passByAddressSwap(&a, &b);
    cout << a << " " << b << endl;

    passByReferenceSwap(a,b);
    cout << a << " " << b << endl;

    mixPassSwap(&a, b);
    cout << a << " " << b << endl;

    int A[5] = {1, 2, 3, 4, 5};
    passArrayToFunc(A, 5);
    passArrayToFunc(A, 5);

    int *B = returnArrayFromFunc(2);
    passArrayToFunc(B, 2);

    struct Rectangle r = {10, 5};
    cout << "Area of rectangle is: " <<passByValueStruct(r) << endl;

    passByReferenceStruct(&r);
    cout << "Area of rectangle is: " <<passByValueStruct(r) << endl;

    return 0;
}
