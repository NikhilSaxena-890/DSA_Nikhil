#include <iostream>
#include <vector>
using namespace std;



// Recursive function to generate permutations
void recurPermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq) {
    if (ds.size() == nums.size()) { // Base case: if the subset size matches nums size, store it
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) { // If the element is not already picked
            ds.push_back(nums[i]); // Pick the element
            freq[i] = 1; // Mark it as picked
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0; // Unmark (backtrack)
            ds.pop_back(); // Remove last picked element (backtracking)
        }
    }
}



// Function to generate all permutations
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(), 0); // Frequency array to track picked elements
    recurPermute(ds, nums, ans, freq);
    return ans;
}



int main() {
    vector<int> nums = {1, 2, 3}; // Example input

    // Compute all permutations
    vector<vector<int>> result = permute(nums);

    // Print the permutations
    cout << "Permutations are:" << endl;
    for (const auto& perm : result) {
        cout << "{ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }


    
    return 0;
}