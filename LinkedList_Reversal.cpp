#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void push(node *head,int data){
    while(head->next){
        head=head->next;
    }
    node *newnode=new node;
    newnode->data=data;
    head->next=newnode; 
    newnode->next=NULL;
}

void display(node *head){
    while(head)
    {
        cout<<head->data<<" "; head=head->next;
    }
}
node* reversal(node *head){
    node *current=head;
    node *prev=NULL;
    node *nxt=NULL;
    while(current){
        nxt=current->next; //store next
        current->next=prev; //change 1 link of current to prev
        prev=current; //move pointers
        current=nxt; //move pointers, we needed to store this since link between current and next node was broken when we turned current to point to prev
    }
    return prev;
    
}
int main()
{node *head=new node; head->data=0;
    for(int i=1;i<5;++i)push(head,i);
    display(head);
    head=reversal(head);
    display(head);
    
}
