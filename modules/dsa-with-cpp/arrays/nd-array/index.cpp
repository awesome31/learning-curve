/**
 * 2D Array:
 * 1. They are used to represent matrices or tabular data. Although they are called 2D arrays, in memory they are represented linearly.
 * 2. How do compilers deal with 1D Array?
 *  - The way compilers understand and figure out how to change an array or locate an item in an array is using a formula. (L0: Base Address: L0 + (i * r))
 *  - During runtime, the base address is updated.
 *  - The reason the array indices start from 0, and not 1 is because the array formula has one extra operation if it starts from 1.
 * 3. How do compilers deal with 2D Array?
 *  - As mentioned above, 2D arrays are represented linearly in memory.
 *  - Row Major Mapping: In Row Major mapping, the elements of one row, are stored next to each other, followed by the next row. (L0 + (i * n + j) * w)
 *  - Column Major Mapping: In Column Major mapping, the elements of one column are stored next to each other, followed by the next column.
 *  - In terms of time, both mappings are same.
 */
#include <iostream>
using namespace std;

void twoDArrays() {
    //First way to create.
    int A[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 5}, {1, 2, 3, 5}};

    //Second way to create. Array of pointers. Partially in the heap.
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    B[0][0] = 12;
    cout << B[0][0] << endl;

    //Everything in the heap.
    int **C;
    C = new int *[3];
    C[0] = new int[4];
}

void checkAddress() {
    int A[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 5}, {1, 2, 3, 6}};
    cout << A << " " << *((* A + 3) + 3) << endl;
}

int main() {
    twoDArrays();

    checkAddress();
}
