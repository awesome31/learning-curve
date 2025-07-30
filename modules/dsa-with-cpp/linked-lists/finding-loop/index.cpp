#include <iostream>
using namespace std;

class LinkedListNode {
    public:
        int data;
        LinkedListNode *next; //This means we are storing an address.

        LinkedListNode(int data, LinkedListNode *next) {
            this->data = data;
            this->next = next? next: NULL;
        }
};

bool isLoop(LinkedListNode *head) {
    LinkedListNode *p = head;
    LinkedListNode *q = head;

    while(p && q) {
        p = p->next;
        q = q->next;
        q = q? q->next : NULL;

        if(p == q) {
            return true;
        }
    }

    return false;
}

int main() {
    LinkedListNode A(2, NULL);
    LinkedListNode B(3, NULL);
    LinkedListNode C(4, NULL);
    LinkedListNode D(3, NULL);
    LinkedListNode E(3, NULL);

    A.next = &B;
    B.next = &C;
    C.next = &D;
    D.next = &E;

    cout << isLoop(&A) << endl;
}
