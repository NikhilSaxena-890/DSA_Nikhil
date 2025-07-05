#include <iostream>
#include <vector>
#include <algorithm> // Include for sorting

using namespace std;

int maxMinusMin(vector<int>& poles) {
    return *max_element(poles.begin(), poles.end()) - *min_element(poles.begin(), poles.end());
}

bool possible(vector<int>& poles, int cows, int Dis) {
    int count = 1, last = poles[0];
    for (int i = 1; i < poles.size(); i++) {  // Start from index 1
        if (poles[i] - last >= Dis) {
            count++;
            last = poles[i];
        }
    }
    return count >= cows;
}

int minDistance(vector<int>& poles, int cows) {
    sort(poles.begin(), poles.end());  // Sorting is necessary

    int maxD = -1;
    int low = 1, high = maxMinusMin(poles), mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (possible(poles, cows, mid)) {
            maxD = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return maxD;
}

int main() {
    vector<int> poles = {1, 3, 4, 7, 10};
    int cows = 4;
    cout << minDistance(poles, cows);
    return 0;
}
