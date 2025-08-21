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

int maxDepth(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }

  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
  TreeNode *root = generateTreeD();

  cout << maxDepth(root) << endl;
}
