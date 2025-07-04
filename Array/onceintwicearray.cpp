#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//[1,1,2,3,3,4,4]

int bruteForce(int arr[],int n){//O(n^2)
   int c=0;
    for (int i = 0; i < n; i++)
    {
       int num=arr[i];
       for (int j = 0; j < n; j++)
       {
        if(num==arr[j]){
            c=c+1;
        }
       }
     
       if(c<2){
         return num;
       }
         c=0;
    }
}
int bettersoln(int arr[],int n){//O(4n) using hashing technique
    //hashing
    int max=0;
    for (int i = 0; i < n; i++)
    {
       if(max<arr[i]){
        cout<<arr[i];
        max=arr[i];
       }
       else{
        max=max;
       }
    }
    cout<<max;
    int maxarr[max]={0};
    for (int i = 0; i < max; i++)
    {
       cout<<maxarr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        int num=arr[i];
       maxarr[num]=1;
    }
   
    for (int i = 1; i < max; i++)
    {
        if(maxarr[i]==0){
            max=i;
            break;
        }
    }
    return max;
    
}
int optimalsoln(int arr[],int n){
    int x=0;
    for (int i = 0; i < n; i++)
    {
       x^=arr[i];
    }
    
    return x;
}

int main(){
    int arr[9]={1,3,2,1,3,4,4,5,5};
    cout<<optimalsoln(arr,9);
    return 0;
}