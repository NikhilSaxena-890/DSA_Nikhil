#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            temp1 = (temp1 == nullptr) ? headB : temp1->next;
            temp2 = (temp2 == nullptr) ? headA : temp2->next;
        }
        
        return temp1;  // Returns the intersection node or nullptr if no intersection
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Test case
int main() {
    // Creating an example intersection list
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = new ListNode(9);
    headA->next->next->next = common;  // Intersection at node 8

    ListNode* headB = new ListNode(5);
    headB->next = common;  // Intersection at node 8

    Solution solution;
    ListNode* intersection = solution.getIntersectionNode(headA, headB);

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}
