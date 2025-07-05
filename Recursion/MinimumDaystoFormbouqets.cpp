#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Min(const vector<int>& arr) {
    int minVal = INT_MAX;
    for (int val : arr) {
        if (val < minVal) minVal = val;
    }
    return minVal;
}

int Max(const vector<int>& arr) {
    int maxVal = INT_MIN;
    for (int val : arr) {
        if (val > maxVal) maxVal = val;
    }
    return maxVal;
}

bool Possible(const vector<int>& arr, int D, int M, int K) {
    int count = 0, bouquets = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= D) {
            count++;
            if (count == K) { 
                bouquets++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return bouquets >= M;
}

int minDaysLS(vector<int>& arr, int M, int K) {
    if (M * K > arr.size()) return -1;

    for (int i = Min(arr); i <= Max(arr); i++) {
        if (Possible(arr, i, M, K)) {
            return i;
        }
    }
    return -1;
}

int minDays(vector<int>& arr, int M, int K) {
     
     if(arr.size()<M*K) return -1;
     int low=Min(arr);
     int mid,high=Max(arr);

     while(low<=high){
        mid=(low+high)/2;
        if(Possible(arr,mid,M,K)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     return low;
}

int main() {
    vector<int> arr = {1, 10, 3, 10, 2};
    int M = 3, K = 1;
    cout << minDaysLS(arr, M, K) << endl;
    cout << minDays(arr, M, K) << endl;
    return 0;
}
