#include<iostream>
using namespace std;
struct node{
	int data;
	node *next=NULL;
	node *prev=NULL;
};

void inbeg(node **hr,int value){
	node *temp=new node;
	temp->data=value;
	
	if(*hr==NULL) *hr=temp;
	else
	{
		temp->next=*hr;
		*hr=temp;
	}
	
}

void display(node *head){ if(!head) {cout<<"List empty!\n"; return;
}
	while(head){ cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}

void middle(node *head){
	if(head){
		node *slow,*fast;
		slow=fast=head;
		while(fast&&fast->next){
			fast=fast->next->next;
			slow=slow->next;
		}
		cout<<"Middle element is: "<<slow->data<<endl;
	}
	else cout<<"List empty!\n";
}


int main()
{
	node *head=NULL;
	int choice,value;
	while(1){cout<<"1.Insert at beginning\n2.Get Middle\n3.Display\n4.Exit\n";
	cin>>choice;
	switch(choice){
		
		case 1:
			cout<<"Value? ";cin>>value;
			inbeg(&head,value);
			break;
		case 2:
			middle(head);
			break;
		case 3:
			display(head);
			break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"Invalid choice";
		}
	}
}

