/**
 * Pointers in C and CPP.
 * 1. Pointers store address to a data variable.
 * 2. A computer program cannot the heap part of the memory. It can only access the Stack part of the main memory.
 * 3. To access anything that is not on the stack, we make use of pointers.
 * 4. They are also used for parameter passing (will see in an example)
 * 5. Whenever we write `malloc` we get memory inside heap. new keyword is used in CPP.
 * 6. EVERY POINTER takes the same amount of memory.
 */


#include <cstdlib>
#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    int a = 10;
    int *p = &a; //This is how we initialize the pointer.
    cout << p << endl;
    cout << *p << endl; //This is how we get the data out of the pointer.

    //This is how it is done in C.
    int *newP;
    newP = (int*)(malloc(5 * sizeof(int))); //malloc returns a void pointer.
    newP[0] = 12;
    newP[1] = 15;
    cout << newP << endl;
    cout << *newP << endl;

    //This is how its done in CPP.
    int *cppP;
    cppP = new int[5];
    cout << cppP << endl;

    //Arrays are always pointers.
    int A[5] = {1, 2, 3, 4, 5};
    cout << A << endl;

    //This is how you can delete values.
    delete [] cppP;
    delete [] newP;

    int num = 5;
    int &numRef = num; //This means reference. This is just alias.
    cout << num << endl;
    cout << numRef << endl;

    struct Rectangle r = {5, 10};
    struct Rectangle *recP;
    recP = &r;
    cout << "Length of Rectangle is: " << (*recP).length << endl;
    cout << "Breadth of Rectangle is: " << recP->breadth << endl;

    struct Rectangle *pRec;
    pRec = (struct Rectangle*)(malloc(sizeof(struct Rectangle)));
    pRec->breadth = 34;
    pRec->length = 10;
    cout << pRec->length * pRec->breadth << " is the area of the rectangle prec." << endl;

    return 0;
}
