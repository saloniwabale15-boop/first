#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: if root is null, or root matches one of the nodes
    if (!root || root == p || root == q) return root;

    // Recurse on left and right subtrees
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If p and q are found in different subtrees, root is the LCA
    if (left && right) return root;

    // Otherwise, return whichever subtree has p or q
    return left ? left : right;
}

// Helper function to create a new node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    
    TreeNode* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    TreeNode* p = root->left;   // Node 5
    TreeNode* q = root->right;  // Node 1

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA: " << lca->val << endl; // Output should be 3

    return 0;
}