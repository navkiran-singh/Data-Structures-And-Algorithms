#include<iostream>
#include<queue>
using namespace std;

struct node{
	int key;
	node *left;
	node *right;
};
node * NEWNODE(int value){
	node *temp=new node;
	temp->left=temp->right=NULL;
	temp->key=value;
	return temp;
}

node * insert(node *root, int value){
	queue<node *> q;
	if (root==NULL) {root=NEWNODE(value); return root;}
	
	q.push(root);
	
	while(!q.empty()){
		node *temp=q.front(); q.pop();
		if(temp->left==NULL){
			temp->left=NEWNODE(value);
			break;
		}
		else if(temp->left!=NULL) q.push(temp->left);
		
		if(temp->right==NULL){
			temp->right=NEWNODE(value);
		break;}
		else if(temp->right!=NULL) q.push(temp->right);
	}
	return root;
}
void deleteT(node *root){
    if(root==NULL) return;
    deleteT(root->left);
    deleteT(root->right);
    delete(root);
}
//deleteT leaves a dangling pointer
void delete_wrapper(node **root){
  deleteT(*root);
  *root=NULL;
}
void print(node *root){
	if(root){
		print(root->left);
		cout<<root->key<<" ";
		print(root->right);
	}
}
void print_wrapper(node *root){
    if(root) print(root);
    else cout<<"Tree is empty!\n";
}

int main(){
	node *root=NULL;
	cout<<"Enter Tree size, followed by values: (Tree will be created Level by Level Order) \n";
	int size; cin>>size; int value;
	for(int i=0;i<size;++i){
			cin>>value;
 			root=insert(root,value);	
	}
	cout<<"Inorder traversal of the tree is:\n";
	print_wrapper(root);
	delete_wrapper(&root);
	cout<<"\nRunning delete...After deletion operation!\n";
	print_wrapper(root);
	
}