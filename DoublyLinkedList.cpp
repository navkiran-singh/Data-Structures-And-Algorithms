#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
void push(node **head_ref, int data){
node *newnode=new node;
newnode->next=*head_ref;
newnode->prev=NULL;
newnode->data=data;

if(*head_ref)
(*head_ref)->prev=newnode;

*head_ref=newnode;

}
void display(node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}

void reverse(node **head_ref){
    node *temp,*current;
    current=*head_ref;
    while(current)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    *head_ref=temp->prev;
}
void deletenode(node *head, int index){
    node *current=head;
    int count=1;
    node *temp;
    if(current==NULL) return;
    while(current!=NULL)
    {   if(index==count)
    {
        temp=current;
        if(current->prev!=NULL)
        current->prev->next=current->next;
        if(current->next!=NULL)
        current->next->prev=current->prev;
        delete(temp);
    }
    current=current->next;
        count++;
    }
}
int main()
{
    node *head1=NULL;
    push(&head1,10);
    push(&head1,20);
    push(&head1,30);
    push(&head1,40);
    display(head1);
    reverse(&head1);
    deletenode(head1,2);
    display(head1);
}
