#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> NGE(nums.size(), -1);
    stack<int> st;
    
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            NGE[i] = st.top();
        }
        st.push(nums[i]);
    }
    
    return NGE;
}

int main() {
    vector<int> nums = {5, 9, 2, 10, 8};  // Modified input
    vector<int> result = nextGreaterElement(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
