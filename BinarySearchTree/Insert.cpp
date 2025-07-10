#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class with insertIntoBST
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

// Optional: inorder traversal to test correctness
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper: Build BST from vector (only for strictly BST order insert)
TreeNode* buildBST(const vector<int>& values) {
    TreeNode* root = nullptr;
    Solution sol;
    for (int val : values) {
        root = sol.insertIntoBST(root, val);
    }
    return root;
}

int main() {
    Solution sol;

    vector<int> initial = {4, 2, 7, 1, 3};
    int insertVal = 5;

    TreeNode* root = buildBST(initial);

    cout << "Inorder before insertion: ";
    inorder(root);
    cout << endl;

    root = sol.insertIntoBST(root, insertVal);

    cout << "Inorder after insertion of " << insertVal << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
