#include<iostream>
using namespace std;
struct node{
  int data;
  node *next;
};
void pushb(node **hr, int value)
{
    node *temp=new node;
    temp->data=value; temp->next=*hr;
    *hr=temp;
}
void display(node *h){
    while(h!=NULL){
        cout<<h->data<<" ";
        h=h->next;
    }
}
node * reverse(node *head,int k=2){
    int count=0;
    node *current=head;
    node *nxt=NULL;node *prev=NULL;
    while(current!=NULL&&count<k){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
        count++;
    }
   
    if(current!=NULL){
        head->next=reverse(current,k);
    }
    return prev;
}
int main(){node *head=NULL;
for(int i=0;i<10;++i) pushb(&head,i);
head=reverse(head,3);
display(head); 

}
