#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int bruteForce(int arr[],int n){// TC:O(N^2),SC:O(1)
    int major=-1;
    for (int i = 0; i < n; i++)
    {
        int count=0;
        for (int  j = 0; j < n; j++)
        {
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>n/2){
            major=arr[i];
            break;
        }        
    }
    
    return major;
}
int bettersoln(int arr[],int n){// TC:O(2N),SC:O(N)
    int major=-1;
    int dummy[n]={0};
    for (int i = 0; i < n; i++)
    {
       dummy[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if(dummy[i]>n/2){
            major=i;
        }
    }
      
    return major; 
}
int optimalsoln(int arr[], int n){//moore's voting algorithm TC:O(2N),SC:O(1)
    int major;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(count==0){
            count=1;
            major=arr[i];
        }
        else if(arr[i]==major){
            count++;
        }
        else{
            count--;
        }
    }
    count=0;
    for (int i = 0; i < n; i++)
    {
       if(arr[i]==major){
        count++;
       }   
    }
    if(count<float(n)/2){
        major=-1;
    }
    
    return major;
}
int main(){
    int arr[7]={1,2,3,3,2,2,2};
    cout<<optimalsoln(arr,7);
    return 0;
}