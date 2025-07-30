#include<iostream>
using namespace std;

int calculateSumOfNaturalNumbers(int n) {
    if(n == 0) {
        return 0;
    }

    return calculateSumOfNaturalNumbers(n - 1) + n;
}

int main() {
    cout << calculateSumOfNaturalNumbers(5) << endl;
    cout << calculateSumOfNaturalNumbers(6) << endl;
    cout << calculateSumOfNaturalNumbers(7) << endl;
    cout << calculateSumOfNaturalNumbers(8) << endl;
}
