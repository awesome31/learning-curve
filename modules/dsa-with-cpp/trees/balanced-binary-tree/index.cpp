/**
 * Given a binary tree, determine if it is height-balanced.
 *
 * A height-balanced binary tree is a binary tree in which the depth of the two
 * subtrees of every node never differs by more than one.
 */

#include "../Tree.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <stack>

/**
3
/ \
9   20
 /  \
15   7
 */

//[1,2,2,3,null,null,3,4,null,null,4]

TreeNode *generateTreeD() {
  TreeNode *root = new TreeNode(3);

  TreeNode *first = new TreeNode(9);
  TreeNode *second = new TreeNode(20);

  TreeNode *third = new TreeNode(15);
  TreeNode *fourth = new TreeNode(7);

  TreeNode *five = new TreeNode(7);

  root->left = first;
  root->right = second;

  second->left = third;
  second->right = fourth;

  // fourth->left = five;

  return root;
}

int dfsHeight(TreeNode *root) {
  if (root == NULL)
    return 0;

  int leftHeight = dfsHeight(root->left);
  if (leftHeight == -1)
    return -1;
  int rightHeight = dfsHeight(root->right);
  if (rightHeight == -1)
    return -1;

  if (abs(leftHeight - rightHeight) > 1)
    return -1;
  return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root) {
  if (!root) {
    return true;
  }

  return dfsHeight(root) != -1;
}

int main() {
  TreeNode *root = generateTreeD();

  cout << isBalanced(NULL) << endl;
}
