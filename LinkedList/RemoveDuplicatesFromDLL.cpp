#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

Node* removeDuplicates(Node* head) {
    if (!head) return head;
    
    Node* curr = head;
    while (curr->next) {
        if (curr->val == curr->next->val) {
            Node* temp = curr->next;
            curr->next = temp->next;
            if (temp->next) 
                temp->next->prev = curr;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

Node* insert(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    
    Node* tail = head;
    while (tail->next) tail = tail->next;
    
    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 4);
    head = insert(head, 5);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
