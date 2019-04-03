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
int main(){node *head=NULL; //removal of NULL here gives segmentation fault!
pushb(&head,1);
pushb(&head,2);
display(head);
}
