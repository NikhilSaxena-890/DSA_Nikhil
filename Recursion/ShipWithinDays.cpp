#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& wt, int capacity, int D) {
    int days = 1, load = 0;
    for (int i = 0; i < wt.size(); i++) {
        if (load + wt[i] > capacity) {
            days++;  // Start a new day
            load = wt[i]; // Load the first package of the new day
        } else {
            load += wt[i];
        }
    }
    return days <= D;
}

int Max(vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) maxVal = num;
    }
    return maxVal;
}

int Sum(vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num; // Fixed the typo
    }
    return sum;
}

int shipWithinDays(vector<int>& arr, int D) {
    int low = Max(arr), high = Sum(arr), mid, ans = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (isPossible(arr, mid, D)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int D = 5;
    cout << "Minimum capacity required: " << shipWithinDays(weights, D) << endl;
    return 0;
}
