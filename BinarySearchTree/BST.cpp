#include <iostream>
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

// BST Class
class BST {
private:
    Node* root;

    // Helper: insert
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        // Duplicate values not allowed
        return node;
    }

    // Helper: search
    bool search(Node* node, int val) {
        if (node == nullptr)
            return false;
        if (node->data == val)
            return true;
        if (val < node->data)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    // Helper: inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Public methods
    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    // Inserting values
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Traversal
    cout << "Inorder traversal: ";
    bst.inorder();

    // Searching values
    cout << "Search 60: " << (bst.search(60) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (bst.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}
