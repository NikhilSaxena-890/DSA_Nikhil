#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            second->next = curr;
            curr->next = nextPair;

            if (prev) prev->next = second;

            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a test list
ListNode* createTestList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    return head;
}

int main() {
    Solution sol;
    ListNode* head = createTestList();

    cout << "Original List: ";
    printList(head);

    ListNode* swappedHead = sol.swapPairs(head);

    cout << "Swapped List: ";
    printList(swappedHead);

    return 0;
}
