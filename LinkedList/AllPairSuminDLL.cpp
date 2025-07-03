#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

Node* findTail(Node* head) {
    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;
    return tail;
}

vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> ans;
    if (!head) return ans;
    
    Node* left = head;
    Node* right = findTail(head);

    while (left != nullptr && right != nullptr && left->val < right->val) {
        int sum = left->val + right->val;
        if (sum == k) {
            ans.push_back({left->val, right->val});
            left = left->next;
            right = right->prev;
        } else if (sum < k) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }
    return ans;
}

Node* insert(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    
    Node* tail = findTail(head);
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
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    
    cout << "Doubly Linked List: ";
    printList(head);
    
    int k = 7;
    vector<pair<int, int>> pairs = findPairs(head, k);
    
    cout << "Pairs with sum " << k << ": ";
    for (auto p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
