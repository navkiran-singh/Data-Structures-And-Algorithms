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
void max(node *head){
	if(!head) cout<<"List empty!\n";
	else{
	int max=head->data;
	while(head){
		if(head->data>max) max=head->data;
		head=head->next;
	}
	cout<<"Max value is: "<<max<<endl;
}
}
int main()
{
	node *head=NULL;
	int choice,value;
	while(1){cout<<"1.Insert at beginning\n2.Get Maximum\n3.Display\n4.Exit\n";
	cin>>choice;
	switch(choice){
		
		case 1:
			cout<<"Value? ";cin>>value;
			inbeg(&head,value);
			break;
		case 2:
			max(head);
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

