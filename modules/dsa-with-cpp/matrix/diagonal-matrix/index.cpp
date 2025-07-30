/**
 * In diagonal matrix, only the diagonal elements are present.
 * 1. The idea is to create a data structure, that can help in storing these matrices. Instead of creating a 2D matrix, where most of the elements are 0, we can create a single dimension array.
 * 2. For storing any matrix, we can use a formula to access the elements of a matrix.
 */

#include <iostream>
using namespace std;

class DiagonalMatrix {
    private:
        int n;
        int *A;
    public:
        DiagonalMatrix(int n) {
            this->n = n;
            A = new int[n];
        }

        void set(int i, int j, int x) {
            if(i == j) {
                A[i - 1] = x;
            }
        }

        int get(int i, int j) {
            if(i == j) {
                return A[i - 1];
            } if(i < n && j < n) {
                return 0;
            }

            return -1;
        }

        void display() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j) {
                        cout << A[i] << " ";
                    } else {
                        cout << 0 << " ";
                    }
                }

                cout << endl;
            }
        }

        ~DiagonalMatrix() {
            delete [] A;
        }
};

int main() {
    DiagonalMatrix dm(5);

    dm.set(1, 1, 2);
    dm.set(2, 2, 2);
    dm.set(3, 3, 2);
    dm.set(4, 4, 2);
    dm.set(5, 5, 2);

    cout << dm.get(2, 2) << endl;
    cout << dm.get(3, 2) << endl;

    dm.display();
}
