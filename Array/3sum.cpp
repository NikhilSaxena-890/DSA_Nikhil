#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> brute3sum(vector<int>& nums) {
    set<vector<int>> s;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

vector<vector<int>> better3sum(vector<int>& nums) {
    set<vector<int>> s;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

vector<vector<int>> optimal3sum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return ans;
}

void printResult(const vector<vector<int>>& res) {
    for (const auto& triplet : res) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Brute Force Approach:\n";
    printResult(brute3sum(nums));

    cout << "\nBetter Approach:\n";
    printResult(better3sum(nums));

    cout << "\nOptimal Approach:\n";
    printResult(optimal3sum(nums));

    return 0;
}
