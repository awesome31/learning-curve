/**
Given the root of a binary tree, determine if it is a valid binary search tree
(BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the
node's key. The right subtree of a node contains only nodes with keys strictly
greater than the node's key. Both the left and right subtrees must also be
binary search trees.
 */

#include "../Tree.h"
#include <iostream>
#include <vector>

TreeNode *generateTreeD() {
  //[4,2,7,1,3,6,9]
  TreeNode *root = new TreeNode(5);

  TreeNode *first = new TreeNode(1);
  TreeNode *second = new TreeNode(4);

  TreeNode *third = new TreeNode(3);
  TreeNode *fourth = new TreeNode(6);

  root->left = first;
  root->right = second;

  second->left = third;
  second->right = fourth;

  return root;
}

void inorder(TreeNode *root, vector<int> *a) {
  if (root == NULL) {
    return;
  }

  inorder(root->left, a);
  a->push_back(root->val);
  inorder(root->right, a);
}

bool isValidBST(TreeNode *root) {
  vector<int> a;

  inorder(root, &a);

  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  TreeNode *root = generateTreeD();

  cout << isValidBST(root) << endl;
}