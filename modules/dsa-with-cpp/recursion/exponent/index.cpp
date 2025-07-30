#include<iostream>
using namespace std;

int exponent(int m, int n) {
    if(n == 0) {
        return 1;
    }

    return m * exponent(m, n - 1);
}

int exponent2(int m, int n) {
    if(n == 0) {
        return 1;
    }

    if(n % 2 == 0) {
        return exponent(m * m, n /2);
    } else {
        return m * exponent(m * m, (n - 1) / 2);
    }
}

int main() {
    cout << exponent(2, 5) << endl;
    cout << exponent(2, 8) << endl;

    return 0;
}
