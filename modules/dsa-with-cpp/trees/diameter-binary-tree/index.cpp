/**
 * Given the root of a binary tree, return the length of the diameter of the
 tree.

 The diameter of a binary tree is the length of the longest path between any two
 nodes in a tree. This path may or may not pass through the root.

 The length of a path between two nodes is represented by the number of edges
 between them.
 */

#include "../Tree.h"
#include <iostream>

static int maxSum = 0;

int maxDepthOfBinaryTree(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }

  int x = maxDepthOfBinaryTree(root->left);
  int y = maxDepthOfBinaryTree(root->right);

  if (x + y > maxSum) {
    maxSum = x + y;
  }

  return 1 + max(x, y);
}

int diameterOfBinaryTree(TreeNode *root) {
  maxDepthOfBinaryTree(root);

  return maxSum;
}

int main() {}