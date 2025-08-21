/**
 * !Types of Recursion:
 * 1. Tail Recursion: Tail recursion is a kind of recursion, where first the
 * instructions are executed and then towards the end, the recursive function is
 * called. All the operations will be called at calling time. Recursion is heavy
 * in terms of space complexity. Loops are more efficient than tail recursion.
 * Some compilers convert tail recursion into loops to optimise on performance.
 * 2. Head Recursion: In Head Recursion, the first statement itself is the
 * recursive call. All operations will be called at returning time. Loops are
 * more efficient than tail recursion. It is tough to convert a code written in
 * head recursion using loops.
 * 3. Tree Recursion: Tree Recursion is a type of recursion where the recursive
 * call happens MULTIPLE times inside the function.
 * 4. Indirect Recursion: In Indirect Recursion, the function calls another
 * function that calls the first function.
 * 5. Nested Recursion: Nested recursion means that we are passing the parameter
 * of a function as a recursive call.
 */

#include <iostream>
using namespace std;

void recursion(int n) {
  if (n > 0) {
    cout << n << endl;
    recursion(n - 1);
    recursion(n - 1);
  }
}

int main() {
  recursion(3);

  return 0;
}
