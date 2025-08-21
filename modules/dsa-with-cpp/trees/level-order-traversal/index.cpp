/**
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 */

#include "../Tree.h"
#include <iostream>
#include <queue>

void display(vector<int> res) {
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  cout << endl;
}

vector<vector<int>> levelOrder2(TreeNode *root) {
  vector<vector<int>> res;
  if (!root) {
    return res;
  }

  queue<TreeNode *> q;
  q.push(root);

  int level = 0;

  while (!q.empty()) {
    vector<int> temp;
    int size = q.size();

    cout << q.size() << endl;

    for (int i = 0; i < size; i++) {
      TreeNode *front = q.front();
      q.pop();

      temp.push_back(front->val);

      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }

    res.push_back(temp);
    level++;
  }

  return res;
}

int main() {
  TreeNode *root = generateTree();

  vector<vector<int>> res = levelOrder2(root);
}
