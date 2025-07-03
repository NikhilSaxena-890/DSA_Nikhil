#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() {
        head = nullptr;
    }
    
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
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    static Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    static Node* addOne(Node* head) {
        head = reverse(head);
        Node* curr = head;
        int carry = 1;

        while (curr) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;

            if (!carry) break;
            if (!curr->next && carry) {
                curr->next = new Node(carry);
                carry = 0;
            }
            curr = curr->next;
        }

        return reverse(head);
    }
};

int main() {
    LinkedList list;
    list.insert(9);
    list.insert(9);
    list.insert(9);

    cout << "Original List: ";
    list.display();

    list.head = LinkedList::addOne(list.head);

    cout << "After Adding 1: ";
    list.display();

    return 0;
}
