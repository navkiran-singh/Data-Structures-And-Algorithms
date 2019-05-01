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


void duplicates(node **head){
	if(*head==NULL||(*head)->next==NULL) return;
	node *outer,*inner,*next2dup;
	outer=*head;
	
	while(outer!=NULL&&outer->next!=NULL){
	
	inner=outer->next;
		while(inner!=NULL){
			
			if(inner->data==outer->data){
				next2dup=inner->next;
				if(inner->prev)
				inner->prev->next=inner->next;
				if(inner->next)
				inner->next->prev=inner->prev;
		delete(inner);
		inner=next2dup;
			}
			else
			inner=inner->next;
			
		}
		outer=outer->next;
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

