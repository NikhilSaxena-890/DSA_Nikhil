#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* node(ListNode* head, ListNode* fast) {
    ListNode* slow = head;
    while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return node(head, fast);
    }
    return nullptr;
}

void printCycleStart(ListNode* head) {
    ListNode* cycleNode = detectCycle(head);
    if (cycleNode) {
        std::cout << "Cycle detected at node with value: " << cycleNode->val << std::endl;
    } else {
        std::cout << "No cycle detected" << std::endl;
    }
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    printCycleStart(head);

    return 0;
}
