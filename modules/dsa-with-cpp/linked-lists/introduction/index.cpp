/**
 * Introduction to Linked Lists
 * 1. The problem with arrays is that the size of an array needs to be decided during compile time and cannot be changed during runtime.
 * 2. With Linked lists, we do not want the size to be fixed.
 * 3. LinkedLists are always created inside heaps.
 * 4. Its a collection of nodes, where each node contains data and pointer to the next node.
 * 5. Unlike Arrays, the addresses are not contigous.
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

class LinkedList {
    LinkedListNode *head;

    public:
        LinkedList(LinkedListNode *head) {
            this->head = head;
        }

        //Traversing is very important.
        void display() {
            LinkedListNode *tempHead = head;

            while(tempHead) {
                cout << tempHead->data << " ";
                tempHead = tempHead->next;
            }

            cout << endl;
        }

        void reverseDisplay(LinkedListNode *head) {
            if(head) {
                reverseDisplay(head->next);
                cout << head->data << " ";
            }
        }
};

int main() {
    //This creates it in heap.
    LinkedListNode *node = new LinkedListNode(2);
    LinkedListNode *node2 = new LinkedListNode(3);
    LinkedListNode *node3 = new LinkedListNode(4);

    node->next = node2;
    node2->next = node3;

    LinkedList *ll = new LinkedList(node);
    ll->display();
    ll->reverseDisplay(node);
}
