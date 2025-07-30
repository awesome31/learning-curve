#include <iostream>
using namespace std;

/**
 * Such a powerful and simple 2 pointer algorithm.
 */
void sortPositiveNegative(int *A, int length) {
    int i = 0, j = length - 1;

    while(i < j) {
        while(A[i] < 0) {
            i++;
        }
        while(A[j] >= 0) {
            j--;
        }

        if(i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}

int main() {
    int A[10] = {-10, -2, 3, 4, 10, -3, 2, 3, 4, -9};

    sortPositiveNegative(A, 10);

    for(int i = 0; i < 10; i++) {
        cout << A[i] << endl;
    }
}
