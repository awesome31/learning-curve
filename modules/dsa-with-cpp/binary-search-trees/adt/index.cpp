/**
    Binary Search Trees are binary trees with the following properties.
    1. Every element in the left subtree of the node is smaller than the node
   element and every element in the right subtree of the node is greater than
   the node element.
   2. Searching becomes very fast because number of comparisions becomes
   significantly low.
   3. BST's DO not have duplicates.
   4. Inorder traversal of a BST is always sorted.

   The drawback of a binary search tree, is that the height of a binary search
   tree can be anything.
 */
#include "../Tree.h"
#include <iostream>

class BinarySearchTree {
public:
  TreeNode *root;

  BinarySearchTree(int value) { root = new TreeNode(value); }

  // For insertion, we first try and search for an element. If it is not found,
  // then we get the last pointers head and depending on if the item was greater
  // or smaller we add a link.
  void insert(int val) {
    TreeNode *tail = NULL;
    TreeNode *head = root;

    while (head != NULL) {
      if (head->val == val) {
        cout << "This node already exists" << endl;

        return;
      }

      if (val > head->val) {
        tail = head;
        head = head->right;
      } else {
        tail = head;
        head = head->left;
      }
    }

    TreeNode *newNode = new TreeNode(val);
    if (val > tail->val) {
      tail->right = newNode;
    } else {
      tail->left = newNode;
    }
  }

  int search(int val) {
    TreeNode *temp = root;

    while (temp) {
      if (temp->val == val) {
        return val;
      } else if (temp->val < val) {
        temp = temp->right;
      } else {
        temp = temp->left;
      }
    }

    return -1;
  }

  void display(TreeNode *root) {
    if (root == NULL) {
      return;
    }

    display(root->left);
    cout << root->val << " ";
    display(root->right);
  }

  TreeNode *inorderPredecessor(TreeNode *root) {
    if (!root) {
      return NULL;
    }

    TreeNode *temp = root;
    if (!temp->left) {
      return temp;
    } else {
      temp = temp->left;
      while (temp->right) {
        temp = temp->right;
      }
    }

    return temp;
  }

  // For deletion of node, we need to search for the value first. If the item is
  // found, then we find the inorder predecessor or successor and make that as
  // the node.
  int deleteNode(int val) {
    TreeNode *temp = root;

    while (temp) {
      if (temp->val == val) {
        TreeNode *p = inorderPredecessor(temp);

        temp->val = p->val;
        delete[] p;

        return 0;
      } else if (temp->val < val) {
        temp = temp->right;
      } else {
        temp = temp->left;
      }
    }

    return -1;
  }
};

int main() {
  BinarySearchTree *btree = new BinarySearchTree(2);

  btree->insert(30);
  btree->insert(20);
  btree->insert(40);
  btree->insert(10);
  btree->insert(25);
  btree->insert(35);
  btree->insert(45);
  btree->insert(42);
  btree->insert(43);

  btree->display(btree->root);
  cout << endl;

  btree->deleteNode(30);

  btree->display(btree->root);
  cout << endl;
}