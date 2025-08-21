/**
Given the roots of two binary trees p and q, write a function to check if they
are the same or not.

Two binary trees are considered the same if they are structurally identical, and
the nodes have the same value.
 */

#include "../Tree.h"
#include <iostream>

TreeNode *generateTreeD() {
  TreeNode *root = new TreeNode(3);

  TreeNode *first = new TreeNode(9);
  TreeNode *second = new TreeNode(20);

  TreeNode *third = new TreeNode(15);
  TreeNode *fourth = new TreeNode(7);

  root->left = first;
  root->right = second;

  second->left = third;
  second->right = fourth;

  return root;
}

// If there traversals are same.
bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == NULL && q != NULL) {
    return false;
  } else if (p != NULL && q == NULL) {
    return false;
  } else if (p == NULL && q == NULL) {
    return true;
  }

  if (p->val == q->val && isSameTree(p->left, q->left) &&
      isSameTree(p->right, q->right)) {
    return true;
  }

  return false;
}

int main() {
  TreeNode *root = generateTreeD();
  TreeNode *root2 = generateTreeD();

  cout << isSameTree(root, root2) << endl;
}
