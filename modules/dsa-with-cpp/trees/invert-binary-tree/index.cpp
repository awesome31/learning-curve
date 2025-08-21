#include "../Tree.h"
#include <iostream>

TreeNode *invertTree(TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }

  TreeNode *leftInvertedTree = invertTree(root->left);
  TreeNode *rightInvertedTree = invertTree(root->right);

  root->left = rightInvertedTree;
  root->right = leftInvertedTree;

  return root;
}

int main() {
  TreeNode *root = generateTree();

  levelOrder(root);
  cout << endl;

  invertTree(root);
  levelOrder(root);
  cout << endl;
}
