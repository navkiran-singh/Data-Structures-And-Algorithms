#include<iostream>
using namespace std;
struct node{
	int data;
	node *next=NULL;
	node *prev;
};

void inbeg(node **hr,int value){
	node *temp=new node;
	temp->data=value;
	temp->prev=NULL;
	
	if(*hr==NULL) {temp->next=NULL;
	*hr=temp;
	}
	else
	{
		temp->next=*hr;
		(*hr)->prev=temp;
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

void deletenode(node *current){
	if(current->next)
	current->next->prev=current->prev;
	if(current->prev)
	current->prev->next=current->next;
	
	delete(current);
}
void duplicates(node **hr){
	if(*hr==NULL||(*hr)->next==NULL) return;
	
	node *one,*two;one=*hr; two=(*hr)->next;
	while(one&&two){
		if(one->data==two->data){
			node *nxt2two=two->next;
			deletenode(two);
			two=nxt2two;
		}
		else{
			one=one->next;
			two=two->next;
		}
	}
	
}
int main()
{
	node *head=NULL;
	int choice,value;
	while(1){cout<<"1.Insert at beginning\n2.Delete Duplicates\n3.Display\n4.Exit\n";
	cin>>choice;
	switch(choice){
		
		case 1:
			cout<<"Value? ";cin>>value;
			inbeg(&head,value);
			break;
		case 2:
			duplicates(&head);
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

