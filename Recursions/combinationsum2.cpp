#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findCombinations(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if(target == 0) {
        ans.push_back(ds);
        return;
    }
    for(int i = ind; i < arr.size(); i++) {
        if(i > ind && arr[i] == arr[i - 1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        findCombinations(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(0, target, candidates, ans, ds);
    return ans;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    
    vector<vector<int>> result = combinationSum2(candidates, target);
    
    cout << "Unique combinations that sum to " << target << " are: \n";
    for (auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
