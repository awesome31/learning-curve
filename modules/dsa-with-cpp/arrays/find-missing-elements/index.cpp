/**
 * Suppose we are given an array
 * [3, 7, 4, 9, 12, 6, 1, 11, 2, 10], we need to find the missing elements
 */
#include <iostream>
using namespace std;

int findMax(int *A, int n) {
    int max = A[0];

    for(int i = 1; i < n; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }

    return max;
}


int findMin(int *A, int n) {
    int min = A[0];

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
        }
    }

    return min;
}

//This is like using a hashtable.
void findMissingElements(int *A, int max, int min, int n) {
    //I have an array here.
    int B[max + 1];

    //Fill them up with zeroes.
    for(int i = 0; i < max + 1; i++) {
        B[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        B[A[i]]++;
    }

    for(int i = 0; i < max + 1; i++) {
        if(i > min) {
            if(B[i] == 0) {
                cout << "Found missing element: " << i << endl;
            }
        }

        cout << B[i] << endl;
    }
}

int main() {
    int arr[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    cout << arr << endl;

    cout << "Maximum element is: " << findMax(arr, 10) << endl;
    cout << "Minimum element is: " << findMin(arr, 10) << endl;

    findMissingElements(arr, findMax(arr, 10), findMax(arr, 10), 10);
}
