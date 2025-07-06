#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printF(int index,vector<int> &ds,int arr[],int n){
    if(index>=n){
    if (ds.size()==0)
    {
        cout<<"{}";
    }
    
       for(auto it:ds){
        cout<<it<<" ";
       }
       cout<<endl;
        return;
    }

    //putting in subsequence
    ds.push_back(arr[index]);
    printF(index+1,ds,arr,n);
    //removing from subsequence
    ds.pop_back();
    printF(index+1,ds,arr,n);
}

int main(){
    int arr[]={1,2,3};
    int n=3;
    vector<int> ds;
    printF(0,ds,arr,n);
    return 0;
}