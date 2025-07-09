#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNext(vector<int>& nums, int end, int start, int num) {
        for (int i = start; i <= end; i++) {
            if (nums[i] > num) {
                return nums[i];
            }
        }
        return -1;
    }

    vector<int> bruteForce(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGE(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if (st.empty()) { 
                NGE[i] = findNext(nums, n - 1, 0, nums[i]);
            } else {
                NGE[i] = st.top();
            }

            st.push(nums[i]);
        }

        return NGE;
    }

    vector<int> optimal(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGE(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if (i < n && !st.empty()) {
                NGE[i] = st.top();
            }

            st.push(nums[i % n]);
        }

        return NGE;
    }
};

int main() {
    vector<int> nums = {5, 9, 2, 10, 8};
    Solution sol;

    cout << "Brute Force Result: ";
    vector<int> bruteResult = sol.bruteForce(nums);
    for (int num : bruteResult) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Optimal Result: ";
    vector<int> optimalResult = sol.optimal(nums);
    for (int num : optimalResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
