/**
 * Queues are linear data structures that follow the First-In-First-Out (FIFO)
 * principle. Queues are logical data structures and can be implemented using
 * arrays or linked lists.
 *
 * 1. We can implement queue using one pointer, but insertion or deletion either
 * requires shifting elements.
 * 2. We can implement queue using two pointers, FRONT AND REAR, which allows
 * efficient insertion and deletion operations.
 *
 * There are drawbacks to implement queues using arrays:
 * - We cannot reuse the spaces of deleted elements. To overcome this, we can
 * use circular queues.
 */

#include <iostream>
using namespace std;

class Queue {
public:
  int size;
  int front;
  int rear;
  int *arr;

  Queue(int size) {
    arr = new int[size];
    front = rear = -1;
  }

  void enqueue(int x) { arr[++rear] = x; }

  void dequeue() {
    if (front == rear) {
      cout << "Queue is empty" << endl;
    } else {
      front++;
    }
  }

  bool isEmpty() { return front == rear; }

  void display() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
    } else {
      for (int i = front + 1; i <= rear; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  Queue q(4);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.display();
  q.dequeue();
  q.display();
}
