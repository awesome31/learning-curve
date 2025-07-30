#include <iostream>
#include <map>
#include <vector>
using namespace std;

void duplicatesInSortedArray() {
    int A[] = {3, 4, 4, 5, 6, 6, 7, 7, 7, 8};

    int count = 0;
    int currentElement = A[0];

    for(int i = 0; i < 9; i++) {
        if(A[i] == A[i + 1]) {
            int j = i + 1;
            while(A[j] == A[i]) j++;

            cout << A[i] << " : " << j - i << endl;
            i = j - 1;
        }
    }
}

/**
 * We can use a hastable. Arrays themselves can be used as hashtables.
 */
bool duplicatesInUnsortedArray() {
    vector<int> A;

    int n = A.size();
    map<int, bool> m;

    for(int i = 0; i < n; i++) {
        auto it = m.find(A[i]);

        if(it != m.end()) {
            return true;
        } else {
            m[A[i]] = true;
        }
    }

    return false;
}

int main() {
    duplicatesInSortedArray();

    cout << duplicatesInUnsortedArray() << endl;
}
