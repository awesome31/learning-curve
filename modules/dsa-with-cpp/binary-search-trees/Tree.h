#ifndef TREENODE_H
#define TREENODE_H

#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

static queue<int> q;

void levelOrder(TreeNode *root) {
  if (!root)
    return;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop();

    cout << current->val << " ";

    if (current->left)
      q.push(current->left);
    if (current->right)
      q.push(current->right);
  }
}

void iterativePreorder(TreeNode *root) {
  TreeNode *t;
  stack<TreeNode *> st;

  t = root;

  while (t != NULL || !st.empty()) {
    if (t != NULL) {
      cout << t->val << " ";
      st.push(t);
      t = t->left;
    } else {
      t = st.top();
      st.pop();

      t = t->right;
    }
  }

  cout << endl;
}

void iterativeInorder(TreeNode *root) {
  TreeNode *t;
  stack<TreeNode *> st;

  t = root;

  while (t != NULL || !st.empty()) {
    if (t != NULL) {
      st.push(t);
      t = t->left;
    } else {
      t = st.top();
      cout << t->val << " ";
      st.pop();

      t = t->right;
    }
  }

  cout << endl;
}

/**
3
/ \
9   20
 /  \
15   7
 */

void iterativePostorder(TreeNode *root) {
  TreeNode *t;
  stack<TreeNode *> st;
  TreeNode *lastVisited = NULL;

  t = root;

  while (t != NULL || !st.empty()) {
    if (t != NULL) {
      st.push(t);
      t = t->left;
    } else {
      TreeNode *peekNode = st.top();

      // This means right nodes are not visited yet.
      if (peekNode->right && lastVisited != peekNode->right) {
        t = peekNode->right;
      } else {
        cout << peekNode->val << " ";
        lastVisited = st.top();
        st.pop();
      }
    }
  }

  cout << endl;
}

TreeNode *generateTree() {
  //[4,2,7,1,3,6,9]
  TreeNode *root = new TreeNode(4);

  TreeNode *first = new TreeNode(2);
  TreeNode *second = new TreeNode(7);

  TreeNode *third = new TreeNode(1);
  TreeNode *fourth = new TreeNode(3);
  TreeNode *fifth = new TreeNode(6);
  TreeNode *sixth = new TreeNode(9);

  root->left = first;
  root->right = second;

  first->left = third;
  first->right = fourth;

  second->left = fifth;
  second->right = sixth;

  return root;
}

#endif // TREENODE_H
