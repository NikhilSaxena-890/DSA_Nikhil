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
    
    Node* prev=head;
    head=head->next;
    head->prev=nullptr;
    free(prev);
    return head;
}//deleteHead TC:O(N) SC:O(1)

Node * deleteAtTail(Node *head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node *prev=temp->prev;
    prev->next=nullptr;
    free(temp);
   
    return head;
}//deleteHead TC:O(N) SC:O(1)

Node * deleteAtKth(Node * head,int k){
   if(head==nullptr){
    return nullptr;
   }
   int c=0;
   Node * temp=head;
   while(temp!=nullptr){
    c++;
    if(c==k)break;
    temp=temp->next;
   }
   Node* Prev=temp->prev;
   Node* Next=temp->next;
   if(Prev==nullptr&&Next==nullptr){
    return nullptr;
   }
   if(Prev==nullptr){
    head=deleteAtHead(head);
    return head;
   }
   if(Next==nullptr){
    head=deleteAtTail(head);
    return head;
   }
   Prev->next=Next;
   Next->prev=Prev;
   return head;
}//TC:O(N) SC:O(1)

Node * deleteAEle(Node * head,int t){
     if(head==nullptr){
    return nullptr;
   }
   Node * temp=head;
   while(temp!=nullptr){
    if(temp->data==t)break;
    temp=temp->next;
   }
   Node* Prev=temp->prev;
   Node* Next=temp->next;
   if(Prev==nullptr&&Next==nullptr){
    return nullptr;
   }
   if(Prev==nullptr){
    head=deleteAtHead(head);
    return head;
   }
   if(Next==nullptr){
    head=deleteAtTail(head);
    return head;
   }
   Prev->next=Next;
   Next->prev=Prev;
   return head;
}// TC:O(N) SC:O(1)

Node * insertAtHead(Node * head, int data){
    Node * temp =new Node(data);
    if(head==nullptr){
        return temp;
    }
    head->prev=temp;
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
    newNode->prev=temp;
    
    return head;
}// TC:O(N) SC:O(1)

Node * insertAtKth(Node * head, int data,int k){
   Node * newNode =new Node(data);
   if(head==nullptr){
    return nullptr;
   }
   int c=0;
   Node * temp=head;
   while(temp!=nullptr){
    c++;
    if(c==k)break;
    temp=temp->next;
   }
   Node* Prev=temp->prev;
   Node* Next=temp->next;
   if(Prev==nullptr&&Next==nullptr){
    return newNode;
   }
   else if(Prev==nullptr){
       head=insertAtHead(head,data);
       return head;
   }
   else if(Next==nullptr){
       head=insertAtTail(head,data);
       return head;
   }
   Prev->next=newNode;
   newNode->prev=Prev;
   Next->prev=newNode;
   newNode->next=Next;
   return head;
}// TC:O(N) SC:O(1)

Node * insertBeforeN(Node * head, int data,int t){
   Node * newNode =new Node(data);
   if(head==nullptr){
    return nullptr;
   }
   Node * temp=head;
   while(temp!=nullptr){
    if(temp->data==t)break;
    temp=temp->next;
   }
   Node* Prev=temp->prev;
   newNode->next=temp;
   Prev->next=newNode;
   newNode->prev=Prev;
   temp->prev=newNode;
   return head;
}// TC:O(N) SC:O(1)

int main(){

    int arr[10]={1,2,3,4,5,6,63,9,10,8};
    Node * head=createLL(arr,10);
    Traversal(head);
    cout<<"\n";
    head=insertAtHead(head,62);
    Traversal(head);
    cout<<"\n";
    head=insertAtTail(head,59);
    Traversal(head);
    cout<<"\n";
    head=insertAtKth(head,57,11);
    Traversal(head);
    cout<<"\n";
    head=insertBeforeN(head,55,57);
    Traversal(head);
    
 
    return 0;
}
    // head=deleteAEle(head,63);
    // head=deleteAtKth(head,7);
    // cout<<LengthLL(head);
    // cout<<searchLL(head,8);