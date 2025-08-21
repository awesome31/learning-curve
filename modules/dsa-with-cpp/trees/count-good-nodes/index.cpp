/**
 * Given a binary tree root, a node X in the tree is named good if in the path
 from root to X there are no nodes with a value greater than X.

 Return the number of good nodes in the binary tree.
 */

#include "../Tree.h"
#include <iostream>
#include <stack>
#include <utility>

TreeNode *generateTreeD() {
  //[4,2,7,1,3,6,9]
  // [2,null,4,10,8,null,null,4]
  TreeNode *root = new TreeNode(2);

  TreeNode *first = new TreeNode(4);
  TreeNode *second = new TreeNode(10);

  TreeNode *third = new TreeNode(8);
  TreeNode *fourth = new TreeNode(4);

  root->right = first;
  first->left = second;
  first->right = third;
  third->left = fourth;

  return root;
}

/**
2
   \
    4
   / \
 10   8
     /
    4
*/
int goodNodes(TreeNode *root) {
  if (!root) {
    return 0;
  }

  stack<pair<TreeNode *, int>> st;
  TreeNode *t = root;
  int currentMax = t->val;
  int goodNodeCount = 0;

  while (!st.empty() || t != NULL) {
    if (t != NULL) {
      if (t->val >= currentMax) {
        goodNodeCount++;
        currentMax = t->val;
      }

      st.push(pair<TreeNode *, int>(t, currentMax));
      t = t->left;
    } else {
      pair<TreeNode *, int> top = st.top();
      st.pop();

      currentMax = top.second;
      t = top.first->right;
    }
  }

  return goodNodeCount;
}

int main() {
  TreeNode *root = generateTreeD();

  cout << goodNodes(root) << endl;
}
