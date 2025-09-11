#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirror images
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function to check if tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

// Driver code
int main() {


    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}