/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <cmath>
#include <iostream>
using namespace std;

class ListNode {
       public:
           int val;
           ListNode *next;

           ListNode(int val) {
               this->val = val;
               next = 0;
           }
};

void traverse(ListNode *head) {
     ListNode *tempHead = head;

     while(tempHead) {
         cout << tempHead->val << " ";
         tempHead = tempHead->next;
     }

     cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carryOver = 0;
    ListNode *head = NULL;
    ListNode *current = NULL;

    while(l1 && l2) {
        int total = l1->val + l2->val + carryOver;

        if(total > 9) {
            total = total - 10;
            carryOver = 1;
        } else {
            carryOver = 0;
        }

        ListNode *digitNode = new ListNode(total);

        cout << l1->val << " " << l2->val << endl;

        if(!head) {
            head = digitNode;
        }

        if(!current) {
            current = digitNode;
        } else {
            current->next = digitNode;
            current = current->next;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1) {
        int total = l1->val + carryOver;

        if(total > 9) {
            total = total - 10;
            carryOver = 1;
        } else {
            carryOver = 0;
        }

        ListNode *digitNode = new ListNode(total);
        current->next = digitNode;
        current = current->next;

        l1 = l1->next;
    }


    while(l2) {
        int total = l2->val + carryOver;

        if(total > 9) {
            total = total - 10;
            carryOver = 1;
        } else {
            carryOver = 0;
        }

        ListNode *digitNode = new ListNode(total);
        current->next = digitNode;
        current = current->next;

        l2 = l2->next;
    }

    if(carryOver) {
        ListNode *digitNode = new ListNode(carryOver);
        current->next = digitNode;
    }

    return head;
}

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    int firstNumber, secondNumber = 0;

    int currentPow = 0;
    while(l1) {
        firstNumber += l1->val * pow(10, currentPow);
        currentPow++;
        l1 = l1->next;
    }

    currentPow = 0;
    while(l2) {
        secondNumber += l2->val * pow(10, currentPow);
        currentPow++;
        l2 = l2->next;
    }
    int total = secondNumber + firstNumber;

    ListNode *head = NULL;
    ListNode *current = NULL;

    while(total) {
        int digit = total % 10;
        total = total / 10;

        ListNode *digitNode = new ListNode(digit);

        if(!head) {
            head = digitNode;
        }

        if(!current) {
            current = digitNode;
        } else {
            current->next = digitNode;
            current = current->next;
        }

    }

    return head;
}

int main() {
    ListNode A(0);
    ListNode B(4);
    ListNode C(7);
    ListNode H(7);

    ListNode D(5);
    ListNode E(6);
    ListNode F(4);
    ListNode G(8);
    ListNode I(1);
    ListNode J(3);


    A.next = &B;
    B.next = &C;
    C.next = &H;

    D.next = &E;
    E.next = &F;
    F.next = &G;
    G.next = &I;
    I.next = &J;

    //7742 + 8465 = 8807
    ListNode *whatever = addTwoNumbers2(&A, &D);
    traverse(whatever);
}
