/**
 * Here we will create the abstract data type for a LinkedList.
 */
#include <cstddef>
#include <iostream>
using namespace std;

class LinkedListNode {
    public:
        int data;
        LinkedListNode *next; //This means we are storing an address.

        LinkedListNode(int data, LinkedListNode *next) {
            this->data = data;
            this->next = next;
        }
};

class LinkedList {
    public:
        LinkedListNode *head;
        LinkedListNode *last;

        LinkedList(int headValue) {
            LinkedListNode *newNode = new LinkedListNode(headValue, NULL);

            head = last = newNode;
        }

        void traverse() {
            LinkedListNode *tempHead = head;

            while(tempHead) {
                cout << tempHead->data << " ";

                tempHead = tempHead->next;
            }

            cout << endl;
        }

        void insertAtLast(int x) {
            LinkedListNode *newNode = new LinkedListNode(x, NULL);

            last->next = newNode;
            last = newNode;
        }

        void deleteAtPosition(int pos) {
            LinkedListNode *p = head;
            LinkedListNode *q = NULL;

            for(int i = 0; i < pos - 1; i++) {
                q = p;
                p = p->next;
            }

            if(p) {
                q->next = p->next;
                delete p;
            }
        }

        bool isSorted() {
            LinkedListNode *p = head->next;
            LinkedListNode *q = head;

            while(p) {
                if(p->data < q->data) {
                    return false;
                }

                p = p->next;
                q = q->next;
            }

            return true;
        }

        void removeDuplicatesInSorted() {
            if(isSorted()) {
                LinkedListNode *q = head;
                LinkedListNode *p = head->next;

                while(p) {
                    if(p->data == q->data) {
                        q->next = p->next;
                        delete p;
                        p = q->next;
                    } else {
                        q = p;
                        p = p->next;
                    }
                }
            }
        }

        //This will reverse a linked list. We have created an auxillary array.
        void reverseByElements() {
            LinkedListNode *tempHead = head;

            int count = 0;
            while(tempHead) {
                count++;
                tempHead = tempHead->next;
            }

            int arr[count];
            tempHead = head;

            while(count--) {
                arr[count] = tempHead->data;
                tempHead = tempHead->next;
            }

            tempHead = head;
            int i = 0;
            while(tempHead) {
                tempHead->data = arr[i];
                tempHead = tempHead->next;
                i++;
            }
        }

        /**
         * The reason reversing links is preferred than reversing elements is BECAUSE, copying elements is an overhead when reversing elements. We do NOT want to modify the contents of Node.
         */
        void reverseByLinks() {
            LinkedListNode *p = head;
            LinkedListNode *q = NULL;
            LinkedListNode *r = NULL;

            while(p) {
                //If I do not dp q = NULL, then R takes a random space in heap!
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            }

            head = q;
        }
};

int main() {
    LinkedList a(1);
    a.insertAtLast(2);
    a.insertAtLast(3);
    a.insertAtLast(4);
    a.insertAtLast(4);
    a.insertAtLast(4);
    a.insertAtLast(5);

    a.traverse();

    a.deleteAtPosition(4);

    a.removeDuplicatesInSorted();

    a.traverse();

    a.reverseByLinks();

    a.traverse();
}
