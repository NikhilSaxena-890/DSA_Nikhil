#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if Koko can eat all bananas within h hours at speed k
bool canEatAll(vector<int>& piles, int h, int k) {
    int hoursNeeded = 0;
    for (int bananas : piles) {
        hoursNeeded += (bananas + k - 1) / k; // Equivalent to ceil(bananas / k)
        if (hoursNeeded > h) return false;
    }
    return true;
}

// Function to find the minimum eating speed
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int result = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canEatAll(piles, h, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> piles = {3, 6, 7, 11}; // Example input
    int h = 8; // Example hours
    int minSpeed = minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << minSpeed << " bananas per hour" << endl;
    return 0;
}
