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

void traverse(LinkedListNode *head) {
    LinkedListNode *tempHead = head;

    while(tempHead) {
        cout << tempHead->data << " ";
        tempHead = tempHead->next;
    }

    cout << endl;
}

//The idea is to create a follow pointer. The tail pointer keeps following head.
LinkedListNode * searchAndMoveToHead(LinkedListNode *head, int key) {
    LinkedListNode *tempHead = head;
    LinkedListNode *tailHead = 0;

    while(tempHead) {
        if(tempHead->data == key) {
            if(tailHead) {
                tailHead->next = tempHead->next;
                tempHead->next = head;

                return tempHead;
            } else {
                return head;
            }
        }

        tailHead = tempHead;
        tempHead = tempHead->next;
    }

    return head;
}

int main() {
    //These are call created in the activation record of the main function itself.
    LinkedListNode node(2);
    LinkedListNode node2(3);
    LinkedListNode node3(4);
    LinkedListNode node4(5);

    node.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    LinkedListNode * newHead = searchAndMoveToHead(&node, 2);

    traverse(newHead);
}
