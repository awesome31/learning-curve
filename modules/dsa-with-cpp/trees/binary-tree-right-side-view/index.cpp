/**
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to bottom.
 */

#include "../Tree.h"
#include <deque>
#include <iostream>

void display(vector<int> res) {
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  cout << endl;
}

vector<int> rightSideView(TreeNode *root) {
  vector<int> res;
  if (!root) {
    return res;
  }

  deque<TreeNode *> q;
  q.push_back(root);

  while (!q.empty()) {
    int size = q.size();
    res.push_back(q.back()->val);

    for (int i = 0; i < size; i++) {
      TreeNode *front = q.front();
      q.pop_front();

      if (front->left) {
        q.push_back(front->left);
      }

      if (front->right) {
        q.push_back(front->right);
      }
    }
  }

  return res;
}

int main() {
  TreeNode *root = generateTree();
  vector<int> res = rightSideView(root);
  display(res);
}
