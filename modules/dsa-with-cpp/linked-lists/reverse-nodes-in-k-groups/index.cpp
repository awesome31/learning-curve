/**
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

 k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

 You may not alter the values in the list's nodes, only nodes themselves may be changed.
 */

#include <iostream>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode *next;

        ListNode(int data) {
            this->data = data;
            next = 0;
        }
};

void traverse(ListNode *head) {
    ListNode *tempHead = head;

    int nodeCount = 0;

    while(tempHead && nodeCount < 10) {
        nodeCount++;
        cout << tempHead->data << " ";
        tempHead = tempHead->next;
    }

    cout << endl;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    int nodeCount = 0;
    ListNode* tempHead = head;

    while(nodeCount !=k && tempHead) {
        nodeCount++;
        tempHead = tempHead->next;
    }

    //The reason it terminated is that nodeCount became equal to K.
    if(nodeCount == k) {
        ListNode *nextHead = reverseKGroup(tempHead, k);

        ListNode *p = head;
        ListNode *q = NULL;
        ListNode *r = NULL;

        while(p != tempHead) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        head->next = nextHead;
        return q;
    }

    return head;
}

int main() {
    ListNode A(1);
    ListNode B(2);
    ListNode C(3);
    ListNode D(4);
    ListNode E(5);
    ListNode F(6);
    ListNode H(7);
    ListNode I(8);

    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = &E;
    E.next = &F;
    F.next = &H;
    H.next = &I;

    ListNode* newHead = reverseKGroup(&A, 2);
    traverse(newHead);
}
