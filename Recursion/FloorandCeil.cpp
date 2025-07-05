#include <iostream>
#include <vector>
using namespace std;

int Floor(vector<int>& arr, int target, int n) {
    int low = 0, high = n - 1, floor = -1;

    while (low <= high) {
        int mid = (low + high) / 2; // Prevents overflow
        if (arr[mid] <= target) {
            floor = arr[mid];  // Possible floor value
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return floor;
}

int Ceil(vector<int>& arr, int target, int n) {
    int low = 0, high = n - 1, ceil = -1;

    while (low <= high) {
        int mid = (low + high) / 2; // Prevents overflow
        if (arr[mid] >= target) {
            ceil = arr[mid];  // Possible ceil value
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ceil;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9}; // Sorted array
    int target;
    
    cout << "Enter target value: ";
    cin >> target;
    
    int floorValue = Floor(arr, target, arr.size());
    int ceilValue = Ceil(arr, target, arr.size());
    
    cout << "Target: " << target << "\n";
    cout << "Floor: " << (floorValue != -1 ? to_string(floorValue) : "No floor found") << "\n";
    cout << "Ceil: " << (ceilValue != -1 ? to_string(ceilValue) : "No ceil found") << "\n";
    
    return 0;
}
