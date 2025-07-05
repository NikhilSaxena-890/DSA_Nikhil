#include <iostream>
#include <vector>
using namespace std;

int SearchInsertPosition(vector<int>& arr, int target, int n) {
    int low = 0, high = n - 1, ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents overflow
        if (arr[mid] >= target) {
            ans = mid;  // Possible insert position
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9}; // Sorted array
    int target;
    
    cout << "Enter target value: ";
    cin >> target;
    
    int index = SearchInsertPosition(arr, target, arr.size());
    
    cout << "Target " << target << " should be inserted at index: " << index << endl;
    
    return 0;
}
