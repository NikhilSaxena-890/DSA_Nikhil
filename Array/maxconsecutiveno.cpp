#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimalsoln(int arr[],int n){//O(n)
    int max=0;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1){
            count++;
        }
        if(count>max){
            max=count;
        }
        if(arr[i]!=1){
            count=0;
        }
    }
    return max;  
}

int main(){
    int arr[10]={1,1,1,1,1,1,1,1,1,0};
    cout<<optimalsoln(arr,10);
    return 0;
}