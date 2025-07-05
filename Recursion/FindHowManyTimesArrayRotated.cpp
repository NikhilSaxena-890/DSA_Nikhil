#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int NoOfRotations(vector<int> &arr) {
    int low = 0, mid;
    int high = arr.size() - 1;
    int minm = INT_MAX;
    int minIndx=-1;

    while (low <= high) {
        mid = (low + high) / 2;

        // Update minm with the current element
        if (arr[low] <= arr[high]) {  // Left half is sorted
            if(minm>= arr[low]){
                minIndx=low;
                minm=arr[low];
            }
            break;  // Move to the right half
        } 

        if (arr[low] <= arr[mid]) {  // Left half is sorted
            if(minm>= arr[low]){
                minIndx=low;
                minm=arr[low];
            }
            low = mid + 1;  // Move to the right half
        } else {  // Right half is sorted
            if(minm>= arr[mid]){
               minIndx=mid;
               minm=arr[mid];
           }
            high = mid - 1;  // Move to the left half
        }
    }

    return minIndx;
}

int main() {
    vector<int> arr = {4, 5, 6, 0,1, 2,3};
    cout << "No of Rotations: " << NoOfRotations(arr) << endl;
    return 0;
}
