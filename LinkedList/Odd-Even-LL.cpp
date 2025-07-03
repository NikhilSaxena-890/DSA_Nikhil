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

// Function to rearrange the linked list into odd-even order
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Edge case: empty list or single-node list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Initialize pointers for odd and even lists
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save the start of the even list

        // Rearrange nodes
        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next; // Link odd node
            even->next = even->next->next; // Link even node
            odd = odd->next; // Move to next odd node
            even = even->next; // Move to next even node
        }

        // Connect the odd list to the even list
        odd->next = evenHead;

        return head;
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
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    // Rearrange the list using the Solution class
    Solution solution;
    ListNode* result = solution.oddEvenList(head);

    // Print the rearranged list
    cout << "Odd-Even Rearranged List: ";
    printList(result);

    return 0;
}
