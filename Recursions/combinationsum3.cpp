#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findCombinations(int k, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int start) {
        if (target == 0 && ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue; // Avoid duplicate combinations
            if (nums[i] > target) break; // No need to proceed further
            
            ds.push_back(nums[i]);
            findCombinations(k, target - nums[i], nums, ans, ds, i + 1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        findCombinations(k, n, nums, ans, ds, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    int k = 4, target = 11;
    vector<vector<int>> result = solution.combinationSum3(k, target);
    
    cout << "Unique combinations of " << k << " numbers that sum to " << target << " are: \n";
    for (auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
