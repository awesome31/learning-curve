/**
 * Doubly Linked lists can be used to traverse in either direction of the Linked Lists.
 */

#include <iostream>
using namespace std;

class DoublyLinkedListNode {
    public:
        int value;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int value) {
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
};

void traverseForwardAndBackward(DoublyLinkedListNode *head) {
    DoublyLinkedListNode *tempHead = head;

    while(tempHead->next) {
        cout << tempHead->value << " ";
        tempHead = tempHead->next;
    }

    cout << tempHead->value << " ";
    cout << endl;

    while(tempHead->prev) {
        cout << tempHead->value << " ";
        tempHead = tempHead->prev;
    }

    cout << tempHead->value << " ";
    cout << endl;
}

int main() {
    DoublyLinkedListNode *A = new DoublyLinkedListNode(1);
    DoublyLinkedListNode *B = new DoublyLinkedListNode(2);
    DoublyLinkedListNode *C = new DoublyLinkedListNode(3);
    DoublyLinkedListNode *D = new DoublyLinkedListNode(4);
    DoublyLinkedListNode *E = new DoublyLinkedListNode(5);

    A->next = B;
    B->prev = A;

    B->next = C;
    C->prev = B;

    C->next = D;
    D->prev = C;

    D->next = E;
    E->prev = D;

    traverseForwardAndBackward(A);
}
