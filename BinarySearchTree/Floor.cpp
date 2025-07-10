#include <bits/stdc++.h>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert function to build BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Inorder traversal (for checking BST structure)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Floor function: largest value <= given val
int findFloor(Node* root, int val) {
    int floor = -1;

    while (root) {
        if (root->data == val) {
            return root->data;
        }

        if (val > root->data) {
            floor = root->data;     // potential floor
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}

int main() {
    Node* root = nullptr;

    // Sample values to insert into BST
    vector<int> values = {8, 4, 12, 2, 6, 10, 14};
    for (int val : values) {
        root = insert(root, val);
    }

    // Display BST structure using inorder traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Test floor function
    vector<int> testValues = {5, 1, 6, 9, 13, 15};
    for (int x : testValues) {
        int f = findFloor(root, x);
        if (f != -1)
            cout << "Floor of " << x << " is: " << f << endl;
        else
            cout << "No floor exists for " << x << endl;
    }

    return 0;
}
