#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& arr, int low, int mid, int high) {
    int l = low;
    int m = mid + 1;
    vector<int> arr2;

    // Merge two halves into arr2
    while (l <= mid && m <= high) {
        if (arr[l] <= arr[m]) {
            arr2.push_back(arr[l]);
            l++;
        } else {
            arr2.push_back(arr[m]);
            m++;
        }
    }

    // Copy remaining elements from left half
    while (l <= mid) {
        arr2.push_back(arr[l]);
        l++;
    }

    // Copy remaining elements from right half
    while (m <= high) {
        arr2.push_back(arr[m]);
        m++;
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < arr2.size(); i++) {
        arr[low + i] = arr2[i];
    }
}

void MergeSort(vector<int>& arr, int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, h);
        Merge(arr, l, mid, h);
    }
}

int main() {
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int l = 0;
    int h = arr.size() - 1;  // Correct array size

    MergeSort(arr, l, h);

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    
    return 0;
}
