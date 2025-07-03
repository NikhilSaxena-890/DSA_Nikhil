#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* findKthNode(Node* head, int k) {
    while (head && k > 1) {
        head = head->next;
        k--;
    }
    return head;
}

Node* rotate(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    
    Node* tail = head;
    int n = 1;
    while (tail->next) {
        tail = tail->next;
        n++;
    }
    
    k = k % n;
    if (k == 0) return head;
    
    tail->next = head; // Create a circular linked list
    Node* newKNodes = findKthNode(head, n - k);
    head = newKNodes->next;
    newKNodes->next = nullptr; // Break the cycle
    
    return head;
}

// Utility function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to append node to linked list
void append(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

int main() {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    
    cout << "Original List: ";
    printList(head);
    
    int k = 2;
    head = rotate(head, k);
    
    cout << "Rotated List: ";
    printList(head);
    
    return 0;
}
