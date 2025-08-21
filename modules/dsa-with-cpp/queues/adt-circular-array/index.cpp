/**
 * The drawback of using arrays to implement the queue is that we cannot reuse
 * the free space again and again. That is why we have the idea of a circular
 * queue.
 *
 * 1. Usually we keep the front pointers, space as empty so that we can
 * distinguish between full and empty conditions.
 */

#include <iostream>
using namespace std;

class CircularQueue {
public:
  int size;
  int front;
  int rear;
  int *arr;

  CircularQueue(int size) {
    this->arr = new int(size);
    this->size = size;
    front = rear = 0;
  }

  void enqueue(int x) {
    if ((rear + 1) % size == front) {
      cout << "Queue is Full" << endl;
    } else {
      rear = (rear + 1) % size;
      arr[rear] = x;
    }
  }

  void dequeue() { front = (front + 1) % size; }

  void display() {
    cout << front << " " << rear << endl;

    if (front > rear) {
      for (int i = front + 1; i <= size; i++) {
        cout << arr[i] << " ";
      }
      for (int i = 0; i <= rear; i++) {
        cout << arr[i] << " ";
      }
    } else {
      for (int i = front + 1; i <= rear; i++) {
        cout << arr[i] << " ";
      }
    }

    cout << endl;
  }
};

int main() {
  CircularQueue q(7);

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  q.enqueue(7);
  q.display();

  q.dequeue();
  q.dequeue();
  q.display();

  q.enqueue(8);
  q.display();
}
