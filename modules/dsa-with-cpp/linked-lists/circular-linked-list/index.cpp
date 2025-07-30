/**
 * Circular Linked Lists:
 * 1. Circular Linked Lists are Linked Lists where the last node is connected back to the head of the LinkedList.
 * 2. If we want a circular data structure, then this is a good choice.
 */

#include <iostream>
using namespace std;

class LinkedListNode {
     public:
         int data;
         LinkedListNode *next;

         LinkedListNode(int data) {
             this->data = data;
             next = 0;
         }
};

void display(LinkedListNode *head) {
    LinkedListNode *tempHead = head;

    do {
        cout << tempHead->data << " ";
        tempHead = tempHead->next;
    } while (tempHead != head);

    cout << endl;
}

int main() {
    LinkedListNode A(1);
    LinkedListNode B(2);
    LinkedListNode C(3);
    LinkedListNode D(4);
    LinkedListNode E(5);
    LinkedListNode F(6);

    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = &E;
    E.next = &F;
    F.next = &A;

    display(&A);
}
