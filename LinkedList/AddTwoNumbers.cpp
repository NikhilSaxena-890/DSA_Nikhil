#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
public:
    Node* head;
    
    LinkedList() {
        head = nullptr;
    }
    
    // Insert at the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Delete a node
    void remove(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Add Two Numbers Represented as Linked Lists
    static Node* AddTwoNumbers(Node* L1, Node* L2) {
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;
        int carry = 0;

        while (L1 || L2 || carry) {
            int sum = carry;
            if (L1) {
                sum += L1->data;
                L1 = L1->next;
            }
            if (L2) {
                sum += L2->data;
                L2 = L2->next;
            }
            curr->next = new Node(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }
        Node* result = dummyNode->next;
        delete dummyNode; // Free unused dummy node
        return result;
    }
};

int main() {
    LinkedList list1, list2;
    list1.insert(2);
    list1.insert(4);
    list1.insert(3);

    list2.insert(5);
    list2.insert(6);
    list2.insert(4);

    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    Node* sumList = LinkedList::AddTwoNumbers(list1.head, list2.head);

    cout << "Sum List: ";
    while (sumList) {
        cout << sumList->data << " -> ";
        sumList = sumList->next;
    }
    cout << "NULL" << endl;

    return 0;
}
