/**
 * Stack is a last in first out data structure.
 *
 * Data:
 *  1. Space for storing elements.
 *  2. Top Pointer.
 */

#include <iostream>
using namespace std;

class Stack {
public:
  int *A;
  int size;
  int topIndex;

  Stack(int size) {
    this->size = size;
    this->A = new int(size);
    this->topIndex = -1;
  }

  void push(int value) {
    if (topIndex == size) {
      return;
    }

    topIndex++;
    A[topIndex] = value;
  }

  int pop() {
    if (topIndex < 0) {
      return -1;
    }

    return A[topIndex--];
  }

  bool isEmpty() {
    if (topIndex == -1) {
      return true;
    } else {
      return false;
    }
  }

  bool isFull() {
    if (topIndex == size) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Stack s(5);

  s.push(5);
  s.push(6);
  s.push(7);
  s.push(8);
  s.push(9);
  s.push(10);

  cout << s.isFull() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.isEmpty() << endl;
}
