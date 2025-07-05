#include <iostream>
#include <vector>
using namespace std;

int calc(int i, int n) {
    long long result = 1;
    while (n > 0) {
        result *= i;
        n--;
    }
    return result;
}

int NthrtLS(int num, int n) {
    if (num == 0) return 0;
    int ans = -1;
    for (int i = 1; i <= num; i++) { // Fix iteration range
        long long cal = calc(i, n);
        if (cal > num) {
            break;
        }
        ans = i;
    }
    return ans;
}

int NthrtBS(int num, int n) {
    if (num == 0) return 0;
    int low = 1, high = num, mid;
    int ans = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        long long power = calc(mid, n);
        
        if (power == num) {
            return mid;
        } else if (power < num) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int num = 66; // Example input
    int n = 4; // Example nth root
    cout << n << "th root of " << num << " (Linear Search): " << NthrtLS(num, n) << endl;
    cout << n << "th root of " << num << " (Binary Search): " << NthrtBS(num, n) << endl;
    
    return 0;
}
