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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int nodeCount = 0;
    ListNode *tempHead = head;

    while(tempHead) {
        tempHead = tempHead->next;
        nodeCount++;
    }

    int nodeToRemove = nodeCount  - n;
    ListNode *p = head;
    ListNode *q = NULL;

    while(nodeToRemove--) {
        q = p;
        p = p->next;
    }

    if(q && p) {
        q->next = p->next;
    }

    if(p == head) {
        return p->next;
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
    // ListNode H(7);

    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = &E;
    E.next = &F;
    // F.next = &H;

    traverse(&A);
    ListNode *newHead = removeNthFromEnd(&A, 1);
    traverse(newHead);
}
