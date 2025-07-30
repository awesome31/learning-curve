/**
 * Character Sets
 * 1. As we know computers only supports numbers. The way that a character is defined is using a standard called ASCII. ASCII codes are specifically for English language.
 * 2. We use Unicode standards, if we want to display other languages.
 * 3. ASCII starts from 65 and ends at 90 for upper case english letters. 97-122 is for upper case letters. For numerical symbols and symbols there are ascii codes. Total 127 ASCII codes are available.
 * 4. Uncodes take 16 bits of memory.
 * 5. Strings are essentially array of characters. \0 is called the string delimitter. This is how the compilers know that there is an EOS.
 */

#include <iostream>
using namespace std;

int findStringLength(char *A) {

    int i = 0;
    while(A[i] != '\0') {
        i++;
    }

    return i;
}

void upperCase() {
    char A[] = "WELCOME";

    int i = 0;
    while(A[i] != '\0') {
        A[i] = A[i] + 32;
        i++;
    }

    cout << A << endl;
}

void countWords() {
    char A[] = "How are       you?";

    int i = 0;
    int spaceCount = 0;
    while(A[i] != '\0') {
        if(A[i] == ' ' && A[i - 1] != ' ') {
            spaceCount++;
        }

        i++;
    }

    cout << A << " has " << spaceCount + 1 << " words" << endl;
}

void reverseAString() {
    char A[] = "Python";
    int length = findStringLength(A);

    char B[length];

    for(int i = length - 1; i >=0; i--) {
        B[i] = A[length - 1 - i];
    }

    cout << B << endl;
}

void checkPalindrome() {
    char A[] = "madabdam";

    int length = findStringLength(A) - 1;
    int i = 0;

    while(i != length && i < length) {
        if(A[i] != A[length]) {
            cout << "Not a palindrom" << endl;
            return;
        }

        i++;
        length--;
    }

    cout << "This is a palindrome" << endl;
}

int main() {
    char temp;
    temp = 'A';
    cout << temp << endl;

    char name[] = "Rohit Tyagi";
    cout << name << endl;

    cout << findStringLength(name) << endl;
    upperCase();
    countWords();
    reverseAString();
    checkPalindrome();
}
