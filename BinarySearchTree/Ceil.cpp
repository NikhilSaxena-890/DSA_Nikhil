#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert function
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Ceil function: smallest node >= val
int findCeil(Node* root, int val) {
    int ceil = -1;

    while (root) {
        if (root->data == val) {
            return root->data;
        }

        if (val < root->data) {
            ceil = root->data;      // potential ceil
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceil;
}

int main() {
    Node* root = nullptr;

    // Insert nodes into BST
    vector<int> values = {8, 4, 12, 2, 6, 10, 14};
    for (int val : values) {
        root = insert(root, val);
    }

    // Optional: display structure
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Test ceil function
    vector<int> testValues = {5, 1, 6, 9, 13, 15};
    for (int x : testValues) {
        int c = findCeil(root, x);
        cout << "Ceil of " << x << " is: ";
        if (c == -1)
            cout << "None" << endl;
        else
            cout << c << endl;
    }

    return 0;
}
