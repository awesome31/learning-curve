/**
 * Introduction to Trees. Let us first understand the terminologies.
 * 1. Nodes: These are the nodes of the trees.
 * 2. Edges: These are the links between nodes. If there are n nodes then there
 * are n - 1 edges in a tree. A root node has no parent edge.
 * 3. Tree is a collection of nodes.
 * 4. Parent: A node is a parent to its very next descendant.
 * 5. Child: A child is a node that is directly connected to another node.
 * 6. Sibling: A sibling is a node that has the same parent as another node.
 * 7. Descendant: A descendant is a node that is connected to another node
 * through a chain of edges.
 * 8. Degree of a node: The degree of a node is the number of its children.
 * Degree of a tree is the maximum degree of its nodes.
 * 9. Leaf: A leaf is a node that has no children.
 * 10. Height: The Height of a tree is the number of edges from the root to the
 * farthest leaf.
 */

/**
 * 1. The formula for number of binary trees with n unlablled nodes is the
 * catalan number (2n c n / n + 1). If the nodes are labelled, the each shape
 * can be generated n! times.
 * 2. The max height of a binary tree is n if there are n nodes.
 * 3. The min height of a binary tree is log2(n + 1) if there are n nodes.
 * 4. Number of nodes with degree 2 is 1 + nodes with degree 0.
 * 5. Strict Binary Tree: A strict binary tree is a binary tree in which each
 * node has either 0 or 2 children. It is the same as full binary tree.
 * 6. Whatever is true for binary trees, are true for n-ary trees.
 */
