#include<iostream>
#include<vector>
using namespace std;

int UpperBound(vector<int>& arr, int target, int n) {
    int low = 0;
    int high = n - 1;
    int ans = n;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target;
    cout << "Enter target value: ";
    cin >> target;
    
    int index = UpperBound(arr, target, arr.size());
    cout << "Lower bound index of " << target << " is: " << index << endl;
    
    return 0;
}