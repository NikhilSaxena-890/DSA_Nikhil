#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minInRotatedSortedArray(vector<int> &arr) {
    int low = 0, mid;
    int high = arr.size() - 1;
    int minm = INT_MAX;

    while (low <= high) {
        mid = (low + high) / 2;

        // Update minm with the current element
        minm = min(minm, arr[mid]);

        if (arr[low] <= arr[mid]) {  // Left half is sorted
            minm = min(minm, arr[low]);
            low = mid + 1;  // Move to the right half
        } else {  // Right half is sorted
            minm = min(minm, arr[mid]);
            high = mid - 1;  // Move to the left half
        }
    }

    return minm;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element: " << minInRotatedSortedArray(arr) << endl;
    return 0;
}
