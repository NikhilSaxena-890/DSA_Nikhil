#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseLL(ListNode* temp) {
    ListNode* prev = nullptr;
    ListNode* curr = temp;
    ListNode* next = nullptr;
    
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* getKthNode(ListNode* temp, int k) {
    k -= 1;
    while (temp && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;
    
    ListNode* temp = head;
    ListNode* prev = nullptr;
    ListNode* newHead = nullptr;
    
    while (temp) {
        ListNode* KthNode = getKthNode(temp, k);
        if (!KthNode) {
            if (prev) prev->next = temp;
            break;
        }
        
        ListNode* nextNode = KthNode->next;
        KthNode->next = nullptr;
        ListNode* reversedHead = reverseLL(temp);
        
        if (!newHead) newHead = KthNode;
        
        if (prev) prev->next = KthNode;
        prev = temp;
        temp = nextNode;
    }
    
    return newHead ? newHead : head;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to append node to linked list
void append(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

int main() {
    ListNode* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 7);
    append(head, 8);
    
    cout << "Original List: ";
    printList(head);
    
    int k = 3;
    head = reverseKGroup(head, k);
    
    cout << "Reversed in k-groups: ";
    printList(head);
    
    return 0;
}
