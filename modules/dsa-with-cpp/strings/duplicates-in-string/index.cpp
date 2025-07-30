/**
 * We can find duplicates in a string by using bitwise operators.
 * 1. Whenever we do left shift, we multiply by 2.
 * 2. Whenever we do right shift, we divide by 2.
 * 3. AND and OR are also bitwise operations.
 * 4. Bitwise operators can ALSO be used as a hashtable.
 */

#include <iostream>
using namespace std;

void bitwiseOperations() {
    int H = 2;
    H = H << 2;
    cout << H << endl;
    H = H >> 2;
    cout << H << endl;

    H = 6 & 10;
    cout << H << endl;
    H = 6 | 10;
    cout << H << endl;

    //Masking: We can check if H > 0, if yes then second bot is set.
    H = 16 & (1 << 2);
    cout << H << endl;

    H = 16 & (1 << 4);
    cout << H << endl;

    //Merging: This will set the second bit to 1.
    H = 16 | (1 << 2);
    cout << H << endl;

    cout << sizeof(int) << endl;
}

bool findDuplicatesInString(char *S) {
    int H = 0;

    for(int i = 0; S[i] != '\0'; i++) {
        int asciiCode = int(S[i]) - 97;

        if((H & (1 << asciiCode)) > 0) {
            return true;
        } else {
            H = H | (1 << asciiCode);
        }
    }

    return false;
}

int main() {
    char S[] = "find";
    cout << findDuplicatesInString(S) << endl;
}
