/**
 * You are given the heads of two sorted linked lists list1 and list2.

 Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

 Return the head of the merged linked list.
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

    while(tempHead) {
        cout << tempHead->data << " ";
        tempHead = tempHead->next;
    }

    cout << endl;
}

ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
    ListNode *last;
    ListNode *third;

    if(p->data < q->data) {
        third=last=p;
        p=p->next;
        third->next=NULL;
    } else
    {
    third=last=q;
    q=q->next;
    third->next=NULL;
    }
    while(p && q)
    {
    if(p->data < q->data)
    {
    last->next=p;
    last=p;
    p=p->next;
    last->next=NULL;
    }
    else
    {
    last->next=q;
    last=q;
    q=q->next;
    last->next=NULL;
    }
    }
    if(p)last->next=p;
    if(q)last->next=q;

    return third;
}


int main() {
    ListNode A(1);
    ListNode B(2);
    ListNode C(4);
    ListNode D(1);
    ListNode E(3);
    ListNode F(4);


    A.next = &B;
    B.next = &C;

    D.next = &E;
    E.next = &F;

    ListNode* newHead = mergeTwoLists(&A, &D);
    traverse(newHead);
}
