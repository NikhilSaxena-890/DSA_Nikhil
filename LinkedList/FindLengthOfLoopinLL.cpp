#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int Length(ListNode* slow) {
        int n = 1;
        ListNode* temp = slow->next;
        while (temp != slow) {
            n++;
            temp = temp->next;
        }
        return n;
    }

    int cycleLength(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return Length(slow); // Return cycle length
            }
        }
        return 0; // No cycle
    }
};

// Helper function to create a cycle in the linked list
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return; // No cycle

    ListNode* temp = head;
    ListNode* cycleNode = nullptr;
    int index = 0;
    
    while (temp->next != nullptr) {
        if (index == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }
    temp->next = cycleNode; // Create cycle
}

// Helper function to print the linked list (for debugging)
void printList(ListNode* head, int maxNodes = 20) {
    ListNode* temp = head;
    int count = 0;
    while (temp != nullptr && count < maxNodes) {
        cout << temp->val << " -> ";
        temp = temp->next;
        count++;
    }
    if (count == maxNodes) cout << "... (cycle may exist)";
    else cout << "NULL";
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> cycle at node 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    // Creating a cycle at node index 2 (0-based index)
    createCycle(head, 2);

    Solution solution;
    int cycleLen = solution.cycleLength(head);

    if (cycleLen > 0) {
        cout << "Cycle detected! Length of cycle: " << cycleLen << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
