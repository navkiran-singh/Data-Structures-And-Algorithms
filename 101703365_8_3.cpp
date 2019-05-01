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
void print(node *root){
	if(root){
		print(root->left);
		cout<<root->key<<" ";
		print(root->right);
	}
}

int height(node *root){
    if(root==NULL) return -1;
    int rh,lh;
    rh=height(root->right);
    lh=height(root->left);
    if(rh>lh) return rh+1; else return lh+1;
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
	print(root);
	cout<<"\nHeight of the tree is: "<<height(root)<<endl;
}
