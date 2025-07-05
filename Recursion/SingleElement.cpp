#include <iostream>
#include <vector>
using namespace std;

int SingleElementLS(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
            if (nums[i] != nums[i + 1]) return nums[i];
        } else if (i == nums.size() - 1) {
            if (nums[i] != nums[i - 1]) return nums[i];
        } else {
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) return nums[i];
        }
    }
    return -1; // Should not reach here if input follows problem constraints
}

int SingleElementBS(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    
    if (nums.size() == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[high] != nums[high - 1]) return nums[high];

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) 
            return nums[mid];

        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1])) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    
    return -1;
}


int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4}; // Example input
    cout << "Single non-duplicate element LS variation: " << SingleElementLS(nums) << endl;
    cout << "Single non-duplicate element BS variation: " << SingleElementBS(nums) << endl;
    return 0;
}
