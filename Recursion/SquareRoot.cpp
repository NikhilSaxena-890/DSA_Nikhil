#include <iostream>
#include <vector>
using namespace std;

int SqrtLS(int num) {
   int ans=-1;
   for (int i = 0; i < num; i++)
   {
    if (i*i<num)
    {
       ans=i;
    }
    else{
        break;
    }
    
   }
   return ans;
   
}

int SqrtBS(int num) {
    if (num == 0 || num == 1) return num;
    int ans = -1;
    int low = 1, high = num, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (mid <= num / mid) { 
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}


int main() {
    int num=66; // Example input
    cout << "Square Root of "<<num<<" : " << SqrtBS(num) << endl;
    
    
    
    return 0;
}