#include <iostream>
#include <vector>
#include <cmath> // Include cmath for ceil function
using namespace std;

bool isPossible(vector<int>& arr, int divisor, int threshold) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += ceil((double)arr[i] / divisor); // Using built-in ceil function
    }
    return sum <= threshold;
}

int Max(vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) maxVal = num;
    }
    return maxVal;
}

int smallestDivisor(vector<int>& arr, int threshold) {
    int low = 1, high = Max(arr), mid, ans = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (isPossible(arr, mid, threshold)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    cout << smallestDivisor(arr, threshold) << endl;
    return 0;
}
