#include <iostream>
using namespace std;

bool checkPalindrome(int i,string str){
    int n=str.size();
    if(i>=n/2) return true;
    if (str[i]!=str[n-i-1]) return false;
        
    return checkPalindrome(i+1,str);
    
}

int main(){
    string str1="NIKHIL"; 
    string str2="NITIN";
    cout<<checkPalindrome(0,str1)<<endl;
    cout<<checkPalindrome(0,str2)<<endl;
    return 0;
}