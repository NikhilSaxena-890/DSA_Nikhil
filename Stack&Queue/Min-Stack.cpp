#include <iostream>
#include <stack>
#include <limits.h>

class MinStack {
public:
    std::stack<long long> s;
    long long mini;

    MinStack() {
        mini = LLONG_MAX; // Initialize with a large value
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            mini = val;
        } else {
            if (val < mini) {
                s.push(2LL * val - mini); // Store a modified value
                mini = val; // Update min value
            } else {
                s.push(val);
            }
        }
    }
    
    void pop() {
        if (s.empty()) return;

        long long curr = s.top();
        s.pop();
        
        // If the popped value was the modified min, restore the previous min
        if (curr < mini) {
            mini = 2 * mini - curr;
        }

        // If stack becomes empty, reset mini
        if (s.empty()) {
            mini = LLONG_MAX;
        }
    }
    
    int top() {
        if (s.empty()) return -1;

        long long curr = s.top();
        return (curr < mini) ? mini : curr;
    }
    
    int getMin() {
        return s.empty() ? -1 : mini;
    }
};

// ✅ **Main Function for Testing**
int main() {
    MinStack minStack;
    
    minStack.push(5);
    minStack.push(3);
    minStack.push(7);
    
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // 3
    minStack.pop();
    
    std::cout << "Top: " << minStack.top() << std::endl; // 3
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // 3

    minStack.pop();
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // 5

    minStack.pop();
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // -1 (stack is empty)

    return 0;
}
