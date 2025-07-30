#include <iostream>
#include <vector>
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

    int nodeCount = 0;

    while(tempHead && nodeCount < 10) {
        nodeCount++;
        cout << tempHead->data << " ";
        tempHead = tempHead->next;
    }

    cout << endl;
}

/**
 * A better way to do it is to reverse the second half of the linked list and then merge them together.
 */
void reorderList(LinkedListNode *head) {
    LinkedListNode *tempHead = head;
    vector<LinkedListNode *> nodes;

    while(tempHead) {
        nodes.push_back(tempHead);
        tempHead = tempHead->next;
    }

    int leftPointer = 0;
    int rightPointer = nodes.size() - 1;

    while(leftPointer < rightPointer) {
        LinkedListNode *currentNext = nodes[leftPointer]->next;

        nodes[leftPointer]->next = nodes[rightPointer];
        nodes[rightPointer]->next = currentNext;

        leftPointer++;
        rightPointer--;
    }

    nodes[leftPointer]->next = NULL;
}

void reorderList2(LinkedListNode *head) {
    LinkedListNode *tempHead = head;
    LinkedListNode *middle = head;

    //Once we have the middle, we can reverse the linkedlist.
    while(middle) {
        tempHead = tempHead->next;
        middle = middle->next;
        middle = middle? middle->next: NULL;
    }

    LinkedListNode *p = tempHead;
    LinkedListNode *q = NULL;
    LinkedListNode *r = NULL;

    while(p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    tempHead = head;
}

int main() {
    LinkedListNode A(1);
    LinkedListNode B(2);
    LinkedListNode C(3);
    LinkedListNode D(4);
    LinkedListNode E(5);
    LinkedListNode F(6);
    // LinkedListNode H(7);

    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = &E;
    E.next = &F;
    // F.next = &H;

    traverse(&A);
    reorderList2(&A);
    traverse(&A);
}
