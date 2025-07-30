#include <iostream>
using namespace std;

static int fibIsCalled = 0;
static int memoized[10];

/**
 * The issue with this implementation is that, fibonacci is calculate again and again. We can memoize it.
 */
int fibonacci(int n) {
    if (n <= 1) {
        fibIsCalled++;
        memoized[n] = n;
        return n;
    }

    cout << memoized[n - 1] << endl;

    if(memoized[n - 1] == 0) {
        memoized[n - 1] = fibonacci(n - 1);
    }

    if(memoized[n - 2] == 0) {
        memoized[n - 2] = fibonacci(n - 2);
    }

        fibIsCalled++;

    return memoized[n - 1] + memoized[n - 2];
}

int fibonacciLoop(int n) {
    int s = 0;

    for(int i = 1; i < n + 1; i++) {
        s += i;
    }

    return s;
}

int main() {
    cout << fibonacci(10) << endl;
    cout << fibIsCalled << endl;
    return 0;
}
