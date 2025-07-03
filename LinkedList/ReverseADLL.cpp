#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    //constructers for non null values;
    Node(int d,Node* n,Node*p){
        data=d;
        next=n;
        prev=p;
    }//for NULL constructor overriding
    Node(int d){
        data=d;
        next=nullptr;
        prev=nullptr;
    }
};

Node * createLL(int arr[],int n){
    Node * head= new Node(arr[0]);
    Node * mover =head;
    for(int i=1;i<n;i++){
        Node * temp= new Node(arr[i],nullptr,mover);
        mover->next=temp;
        mover=temp;
    }
    cout<<"DLL CREATED"<<"\n";
    return head;
}//Creation  TC:O(N) SC:O(N)

void Traversal(Node *head){
    Node * temp= head;
     while(temp!=nullptr){
        cout<<temp->data<<" ";
       
        temp=temp->next;
        
    }
}//Traversal  TC:O(N) SC:O(1)

Node * ReverseDLL(Node * head){
    if (head==nullptr||head->next==nullptr)
    {
       return head;
    }
    Node * Prev=nullptr;
    Node* curr=head;
    while(curr!=nullptr){
       Prev=curr->prev;
       curr->prev=curr->next;
       curr->next=Prev;
       curr=curr->prev;
    }
    head=Prev->prev;
    return head;
}
int main(){

    int arr[10]={1,2,3,4,5,6,63,9,10,8};
    Node * head=createLL(arr,10);
    Traversal(head);
    cout<<"\n";
    head=ReverseDLL(head);
    Traversal(head);
 
    return 0;
}