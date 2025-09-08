#include <iostream>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode* node, long long low, long long high) {
    if (!node) return true;                     // empty subtree is valid
    if (node->val <= low || node->val >= high)   // value must be strictly inside (low, high)
        return false;

    return isValidBSTHelper(node->left, low, node->val) &&
           isValidBSTHelper(node->right, node->val, high);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    // Example tree:   2
    //                / \
    //               1   3
    TreeNode* root = new TreeNode(2);
    root->left  = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << (isValidBST(root) ? "true" : "false") << endl;

    // cleanup (not strictly needed in small demo)
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}