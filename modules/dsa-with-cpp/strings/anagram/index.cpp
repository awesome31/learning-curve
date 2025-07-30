#include <string>
#include <iostream>
using namespace std;

void logArray(int *A, int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    cout << endl;
}

bool isAnagram(string A, string B) {
    int M[26] = {0};

    for(int i = 0; i < A.size(); i++) {
        M[int(A[i]) - 97]++;
    }

    logArray(M, 26);

    for(int i = 0; i < B.size(); i++) {
            M[int(B[i]) - 97]--;
    }

    for(int i = 0; i < 26; i++) {
        if(M[i] != 0) {
            return false;
        }
    }


    return true;
}

int main() {
    string A = "anagram";
    string B = "gramana";

    cout << isAnagram(A, B) << endl;
}
