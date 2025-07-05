#include <iostream>
#include <vector>
using namespace std;

int kthSmallestNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> arr(n + m);
    int one = 0, two = 0, index = 0;

    // Merge the two sorted arrays
    while (one < n && two < m) {
        if (nums1[one] <= nums2[two]) {
            arr[index++] = nums1[one++];
        } else {
            arr[index++] = nums2[two++];
        }
    }

    // Copy remaining elements from nums1
    while (one < n) {
        arr[index++] = nums1[one++];
    }

    // Copy remaining elements from nums2
    while (two < m) {
        arr[index++] = nums2[two++];
    }

    // Return the k-th smallest element (1-based index)
    return arr[k - 1];  // Adjusted for 0-based indexing
}

int main() {
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {2, 4, 6, 8};
    int k = 2;
    
    cout << "The " << k << "-th smallest number is: " << kthSmallestNumber(nums1, nums2, k) << endl;
    
    return 0;
}
