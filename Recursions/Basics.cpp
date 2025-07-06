#include<iostream>
using namespace std;
void printName(int count,string name){
    if(count>0){
        cout<<name<<endl;
        printName(count-1,name);
    }
}
void printNnumbers(int number){
    if(number>0){
        printNnumbers(number-1);
        cout<<number<<endl;
    }
}
int main(){
    int n=5;
    printName(n,"Nikhil");
    printNnumbers(n);
    return 0;
}