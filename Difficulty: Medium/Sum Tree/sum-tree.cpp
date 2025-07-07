/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    pair<bool, int> solve(Node* root) {
    if (root == NULL) {
        return {true, 0};
    }

    if (root->left == NULL && root->right == NULL) {
        return {true, root->data}; // Leaf node is always a Sum Tree
    }

    pair<bool, int> l = solve(root->left);
    pair<bool, int> r = solve(root->right);

    bool isCurrentSumTree = l.first && r.first && (root->data == l.second + r.second);

    // Return: {is sum tree?, total sum of subtree rooted at this node}
    return {isCurrentSumTree, root->data + l.second + r.second};
}

bool isSumTree(Node* root) {
    return solve(root).first;
}

};