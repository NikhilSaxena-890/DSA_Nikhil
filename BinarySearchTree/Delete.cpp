#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Node with two children
            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }

        return root;
    }

private:
    TreeNode* getMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
};

// Inorder traversal for checking BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Manually creating BST:  4
    //                        / \
    //                       2   7
    //                      / \
    //                     1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key = 2;
    Solution sol;
    root = sol.deleteNode(root, key);

    cout << "Inorder after deleting " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
