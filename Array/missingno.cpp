#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int bruteForce(int arr[],int n){//O(n^2)
    int flag;
    for (int i = 1; i <=n; i++)
    {
       flag=0;
       for (int j = 0; j < n-1; j++)
       {
          if(arr[j]==i){
            flag=1;
          }      
       }
       if(flag==0){
        return i;
       }
       
    }
    return -1;
}
int optimal1math(int arr[],int n){//O(n)
    int sum=n*(n+1)/2;
    int actualsum=0;
    for (int i = 0; i < n-1; i++)
    {
       actualsum+=arr[i];
    }
    return sum-actualsum;   
}
int optimal2xor(int arr[],int n){//O(n)
    int xor1=0,xor2=0;
    
    for (int i = 0; i < n-1; i++)
    {
        xor1^=(i+1);
        xor2^=arr[i];
    }
    xor2^=(n);
    
    return xor1^xor2;
}
int main(){
   int arr[9]={1,2,3,4,5,6,7,8,9};
   int n=9;
   cout<<optimal1math(arr,n+1);
   return 0;
}