/**
 * Recursion:
 * 1. Recursion is a pattern where a function calls itself again and again until a base condition is reached.
 * 2. We can trace recursion using a tree.
 * 3. Generalising Recursion:
 *      - Any statement before the next recursion call is done at CALLING time.
 *      - Any statement after the next recursion call is done at RETURNING time.
 * 4. The difference between a loop and recursion is that a LOOP does not have a returning state. That is the strength of recursion.
 * 5. Static variables are created inside the code section of memory itself. Static variables are global variables.
 */

#include<iostream>
using namespace std;

void recursion(int n) {
    if(n > 0) {
        cout << n << endl;
        recursion(n - 1);
    }
}

void recursion2(int n) {
    if(n > 0) {
        recursion2(n - 1);
        cout << n << endl;
    }
}

int main() {
    recursion(3);
    recursion2(3);
}
