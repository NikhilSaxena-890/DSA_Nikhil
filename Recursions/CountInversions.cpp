#include <iostream>
#include <vector>
using namespace std;

int Merge(vector<int>& arr, int low, int mid, int high) {
    int l = low, m = mid + 1;
    vector<int> temp;
    int count = 0;

    while (l <= mid && m <= high) {
        if (arr[l] <= arr[m]) {
            temp.push_back(arr[l]);
            l++;
        } else {
            temp.push_back(arr[m]);
            count += (mid - l + 1); // Count inversions
            m++;
        }
    }

    while (l <= mid) {
        temp.push_back(arr[l]);
        l++;
    }

    while (m <= high) {
        temp.push_back(arr[m]);
        m++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
    
    return count;
}

int MergeSort(vector<int>& arr, int l, int h) {
    int count = 0;
    if (l < h) {
        int mid = (l + h) / 2;
        count += MergeSort(arr, l, mid);
        count += MergeSort(arr, mid + 1, h);
        count += Merge(arr, l, mid, h);
    }
    return count;
}

int CountInversions(vector<int>& arr) {
    return MergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int inversions = CountInversions(arr);
    
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}