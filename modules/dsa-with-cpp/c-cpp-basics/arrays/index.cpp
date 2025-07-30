/**
 * Arrays are contiguous memory locations that are allocated and used to store same typed values. (characters, booleans)
 * The main memory is divided into 3 parts: Code Section, Stack and Heap. Arrays are defined in the stack.
 */

#include <iostream>
using namespace std;

int main() {
     /**
      * 1. Integers take 4 bytes of memory.
      * 2. We can even skip the size of the array if we are initializing the array.
      * 3. We can use sizeof to know the size of the array. 20 in this case.
      * 4. If I declare the size as 10 and initialize only 5 elements, the next 5 elements will be 0.
      * 5. If I do not initialize the array, then the values will be random locations in memory. (Check B)
      * 6. Size of an array can be defined at runtime as well.
      */
     int A[10] = {2, 4, 6, 8, 10};
     int B[10];

     cout << "The size of this array is: " << sizeof(A) << endl;

     for(int i = 0; i < 10; i++) {
         cout << B[i] << endl;
     }

     int n;
     cout << "Enter Size";
     cin >> n;
     int C[n];

     return 0;
}
