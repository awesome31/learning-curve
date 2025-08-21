/**
 * 1. Here we will create the ADT for a binary tree. We will try to create it
 * using arrays. First way to store binary trees, is to use arrays. The formula
 * is the if I is the parent, then 2i is the left child and 2i+1 is the right
 * child. And the parent is at Floor(i/2).
 *
 * 2. A better representation of Tree is to use Linked Representation using
 * classes. There will be n+1 NULL Pointers. A complete binary tree is where if
 * the array representaiton of the list does not have blank spaces between
 * nodes. In complete binary trees, we fill the elements from left to right.
 *
 * 3. There are 4 types of traversals: PreOrder, PostOrder, Inorder and Level
 * Order.
 */

#include <iostream>
using namespace std;

class TreeNode {
public:
  int value;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

class Tree {
public:
  TreeNode *root;

  Tree(TreeNode *root) { this->root = root; }

  void inorder(TreeNode *currentRoot) {
    if (currentRoot == NULL) {
      return;
    }

    inorder(currentRoot->left);
    cout << currentRoot->value << " ";
    inorder(currentRoot->right);
  }

  void preorder(TreeNode *currentRoot) {
    if (currentRoot == NULL) {
      return;
    }

    cout << currentRoot->value << " ";
    preorder(currentRoot->left);
    preorder(currentRoot->right);
  }

  void postorder(TreeNode *currentRoot) {
    if (currentRoot == NULL) {
      return;
    }

    postorder(currentRoot->left);
    postorder(currentRoot->right);
    cout << currentRoot->value << " ";
  }

  void inorderIterative(TreeNode *currentNode) {}
};

int main() {
  TreeNode *a = new TreeNode(1);
  TreeNode *b = new TreeNode(2);
  TreeNode *c = new TreeNode(3);

  a->left = b;
  a->right = c;

  Tree t(a);

  t.inorder(a);
  cout << endl;
  t.preorder(a);
  cout << endl;
  t.postorder(a);
  cout << endl;
}
