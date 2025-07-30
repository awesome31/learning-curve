#include <iostream>
using namespace std;

int * merge2SortedLists(int *A, int *B, int length1, int length2) {
    int *M = new int[length1 + length2];

    int leftP = 0, rightP = 0, currentIndex = 0;

    while(leftP < length1 && rightP < length2) {
        if(A[leftP] < B[rightP]) {
            M[currentIndex] = A[leftP];
            leftP++;
        } else {
            M[currentIndex] = B[rightP];
            rightP++;
        }

        currentIndex++;
    }

    while(leftP < length1) {
        M[currentIndex] = A[leftP];
        currentIndex++;
        leftP++;
    }

    while(rightP < length2) {
        M[currentIndex] = B[rightP];
        currentIndex++;
        rightP++;
    }

    return M;
}

int main() {
    int A[5] = {3, 8, 16, 20, 25};
    int B[6] = {4, 10, 12, 22, 23, 30};

    int *M = merge2SortedLists(A, B, 5, 6);

    for(int i = 0; i < 5+ 6; i++) {
        cout << M[i] << endl;
    }
}
