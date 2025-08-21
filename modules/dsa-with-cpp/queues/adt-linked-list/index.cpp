/**
 * We can also implement the queue data structure using Linked Lists instead of
 * arrays. Linked lists are a better data structure to use for queue.
 */

#include <iostream>
using namespace std;

class LinkedListNode {
public:
  int value;
  LinkedListNode *next;

  LinkedListNode(int value) {
    this->value = value;
    this->next = NULL;
  }
};

void displayLL(LinkedListNode *head) {
  while (head) {
    cout << head->value << " ";
    head = head->next;
  }

  cout << endl;
}

class LLQueue {
public:
  LinkedListNode *front;
  LinkedListNode *rear;

  LLQueue() { front = rear = NULL; }

  bool isEmpty() { return front == NULL; }

  void enqueue(int val) {
    LinkedListNode *temp = new LinkedListNode(val);

    if (isEmpty()) {
      front = temp;
      rear = temp;
    } else {
      rear->next = temp;
      rear = temp;
    }
  }

  void dequeue() {
    if (front) {
      if (front->next) {
        LinkedListNode *nodeToDelete = front;
        front = front->next;
        delete nodeToDelete;
      } else {
        front = NULL;
        rear = NULL;
      }
    }
  }

  void display() {
    LinkedListNode *tempHead = front;

    while (tempHead) {
      cout << tempHead->value << " ";
      tempHead = tempHead->next;
    }

    cout << endl;
  }
};

int main() {
  LLQueue q;

  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(3);
  q.enqueue(3);
  q.enqueue(3);
  q.display();

  q.dequeue();
  q.display();
}
