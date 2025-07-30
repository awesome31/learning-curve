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

int main() {
    LinkedListNode *head = new LinkedListNode(2);
    LinkedListNode *node2 = new LinkedListNode(3);
    LinkedListNode *node3 = new LinkedListNode(4);
    head->next = node2;
    node2->next = node3;

    int count = 0;
    LinkedListNode *tempHead = head;

    while(tempHead) {
        count++;
        tempHead = tempHead->next;
    }

    cout << count << endl;
}
