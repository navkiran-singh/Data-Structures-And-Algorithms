#include<iostream>
#include<queue>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};

node * insert(node *root,int value){
	if(root==NULL) {
		node *temp=new node;
		temp->data=value;
		temp->left=temp->right=NULL;
		return temp;
	}
	
	if(root->data<=value) root->right=insert(root->right,value);
	else if(root->data>value) root->left=insert(root->left,value);
	return root; 
}
//Currently prints in-order
void print(node *root){
	if(root){
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
}


int main(){
	node *root=NULL;
	cout<<"Enter BST size, followed by values: \n";
	int size; cin>>size; int value;
	for(int i=0;i<size;++i){
			cin>>value;
 			root=insert(root,value);	
	}
	print(root);
}
