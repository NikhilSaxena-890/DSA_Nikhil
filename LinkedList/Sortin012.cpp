#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to sort the linked list containing only 0s, 1s, and 2s
class Solution {
public:
    ListNode* Sortin012(ListNode* head) {
        // Edge case: empty list or single-node list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Dummy nodes for 0s, 1s, and 2s sub-lists
        ListNode* zhead = new ListNode(-1);
        ListNode* ohead = new ListNode(-1);
        ListNode* thead = new ListNode(-1);

        ListNode* zero = zhead;
        ListNode* one = ohead;
        ListNode* two = thead;

        // Traverse the original list
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->val == 0) {
                zero->next = temp;
                zero = zero->next;
            } else if (temp->val == 1) {
                one->next = temp;
                one = one->next;
            } else if (temp->val == 2) {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        // Connect the three sub-lists
        zero->next = (ohead->next != nullptr) ? ohead->next : thead->next;
        one->next = thead->next;
        two->next = nullptr;

        // Return the sorted list (skipping the dummy node)
        return zhead->next;
    }
};

// Helper function to create a new ListNode
ListNode* createNode(int value) {
    return new ListNode(value);
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 2 -> 1 -> 0 -> 1 -> 2 -> 0 -> 2 -> 1
    ListNode* head = createNode(2);
    head->next = createNode(1);
    head->next->next = createNode(0);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(0);
    head->next->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->next->next = createNode(1);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    // Sort the list using the Solution class
    Solution solution;
    ListNode* result = solution.Sortin012(head);

    // Print the sorted list
    cout << "Sorted List (0s, 1s, 2s): ";
    printList(result);

    return 0;
}
