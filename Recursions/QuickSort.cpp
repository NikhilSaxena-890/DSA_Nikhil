#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int l, int h) {
    int pivot = arr[l];
    int i = l, j = h;

    while (i < j) {
        while (arr[i] <= pivot && i < h) i++;  // Avoid accessing out-of-bounds
        while (arr[j] > pivot && j > l) j--;

        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]); // Place pivot at correct position
    return j;
}

void QuickSort(vector<int>& arr, int l, int h) {
    if (l < h) {
        int partitionIndex = partition(arr, l, h);
        QuickSort(arr, l, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, h);
    }
}

int main() {
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int l = 0, h = arr.size() - 1;

    QuickSort(arr, l, h);

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
