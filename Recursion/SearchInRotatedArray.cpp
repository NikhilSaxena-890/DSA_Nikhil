#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Prevents integer overflow

        if (nums[mid] == target) 
            return mid;

        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;  // Search left
            } else {
                low = mid + 1;   // Search right
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;  // Search right
            } else {
                high = mid - 1; // Search left
            }
        }
    }
    return -1;  // Target not found
}

int main() {
    int n, target;
    
    // Input array size
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input target value
    cout << "Enter target value: ";
    cin >> target;

    // Search target in the array
    int index = search(nums, target);

    if (index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
