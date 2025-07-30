/**
 * 1. Structures are a collection of dissimilar data types under one name. Instead of being stored on the stack, they are stored on the heap.
 * 2. They are used to define user defined data types.
 * 3. The size of a struct is the total of the size of its members.
 * 4. It is defined in the stack frame.
 */

#include <cstring>
#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

struct Student {
    int roll;
    char name[25];
    struct Rectangle boxSize;
};

int main() {
    struct Rectangle x = {10, 5};
    cout << "Size of the structure is: " <<sizeof(x) << endl;
    cout << "Area of the rectangle is: " << x.length * x.breadth << endl;

    struct Student stu = {1, "Rohit", x};
    strcpy(stu.name, "Rohan Kumar");
    cout << "Student Name: " << stu.name << stu.boxSize.breadth << endl;

    struct Student mathsClass[1];
    mathsClass[0].roll = 1;
    strcpy(mathsClass[0].name, "Rohit Tyagi");

    for(int i = 0; i < 1; i++) {
        cout << "I am " << mathsClass[i].name << " and my roll number is: " << mathsClass[i].roll << endl;
    }

    return 0;
}
