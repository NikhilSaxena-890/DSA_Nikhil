#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    //constructers for non null values;
    Node(int d,Node* n){
        data=d;
        next=n;
    }//for NULL constructor overriding
    Node(int d){
        data=d;
        next=nullptr;
    }
};

Node * createLL(int arr[],int n){
    Node * head= new Node(arr[0]);
    Node * mover =head;
    for(int i=1;i<n;i++){
        Node * temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    cout<<"Linked List created from array"<< endl;
    return head;
}//Creation  TC:O(N) SC:O(N)

void Traversal(Node *head){
    Node * temp= head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}//Traversal  TC:O(N) SC:O(1)

int LengthLL(Node *head){
    Node * temp= head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}//Traversal  TC:O(N) SC:O(1)

int searchLL(Node *head,int target){
    Node * temp= head;
    int count=-1;
    bool found=false;
    while(temp!=nullptr){
        count++;
        if (temp->data==target)
        {
            found=true;
            break;
        }
         
        temp=temp->next;
    }
    if (!found)
    {
       count=-1;
    }
    
    return count;
}//Traversal  TC:O(N) SC:O(1)

Node * deleteAtHead(Node *head){
    if (head==nullptr||head->next==nullptr)
    {
       return nullptr;
    }
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}//deleteHead TC:O(N) SC:O(1)

Node * deleteAtTail(Node *head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}//deleteHead TC:O(N) SC:O(1)

Node * deleteAtKth(Node * head,int k){
    if(head==nullptr){
        return nullptr;
    }
     Node * temp=head;
    if(k==1){
       
        head=head->next;
        free(temp);
        return head;
    }
    int count=1;
    while(temp!=nullptr){
        count++;
        if(count==k){
            Node * ter=temp->next;
            temp->next=temp->next->next;
            free(ter);
            return head;
        }
        temp=temp->next;
    }
    return head;
}//TC:O(N) SC:O(1)

Node * deleteAEle(Node * head,int t){
    if(head==nullptr){
        return nullptr;
    }
     Node * temp=head;
    if(t==head->data){
       
        head=head->next;
        free(temp);
        return head;
    }
    Node * tem=temp->next;
    while(tem!=nullptr){
        if(tem->data==t){
            temp->next=temp->next->next;
            return head;
        }
        temp=temp->next;
        tem=tem->next;
    }
    return head;
}// TC:O(N) SC:O(1)

Node * insertAtHead(Node * head, int data){
        Node * temp =new Node(data);
    if(head==nullptr){
        return temp;
    }
    temp->next=head;
    head=temp;
    return head;
}// TC:O(1) SC:O(1)

Node * insertAtTail(Node * head, int data){
    Node * newNode =new Node(data);
    Node *temp=head;
    if(head==nullptr){
        return newNode;
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    
    return head;
}// TC:O(N) SC:O(1)

Node * insertAtKth(Node * head, int data,int k){
    Node * newNode =new Node(data);
    Node *temp=head;
    if(head==nullptr){
        return newNode;
    }
    if (k==1)
    {
        return insertAtHead(head,data);
    }
    int count=2;
    while(temp!=nullptr){
        if(count==k){
            break;
        }
        count++;
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
    return head;
}// TC:O(N) SC:O(1)

Node * insertBeforeN(Node * head, int data,int n){
    Node * newNode =new Node(data);
    Node *temp=head;
    if(head==nullptr){
        return newNode;
    }
    if (head->data==n)
    {
        return insertAtHead(head,data);
    }
    while(temp!=nullptr){
        if(temp->next->data==n){
            break;
        }
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
    return head;
}// TC:O(N) SC:O(1)

int main(){
    int arr[10]={1,2,3,4,5,6,63,9,10,9};
    Node * head=createLL(arr,10);
    cout<<"The Linked List is:"<<endl;
    Traversal(head);
    head=insertBeforeN(head,33,1);
    cout<<endl;
    Traversal(head);
    // cout<<endl<<"The Linked List Length is:"<<LengthLL(head);
    //DELETIONS:  head=deleteAtHead(head);//head deletion,head=deleteAtKth(head,100);// kth place deletion,head=deleteAtTail(head);//tail deletion, head=deleteAEle(head,9); // delete element
    //INSERTIONS:   head=insertAtHead(head,330);//Head,  head=insertAtTail(head,330);// Tail,head=insertAtKth(head,330,9);// Kth Position,  head=insertBeforeN(head,330,1);//Before N
    // cout<<endl<<"The Element in Linked List is at:"<<searchLL(head,63)<<"index";
    return 0;
}