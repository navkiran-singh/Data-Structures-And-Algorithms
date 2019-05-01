#include<iostream>
using namespace std;
struct node{
	int key;
	node *left;
	node *right;
};

void inorder(node * root){
node * stack[20];
int top=-1;
while(root||top!=-1){

while(root){
	stack[++top]=root;
	root=root->left;
}
root=stack[top--];
cout<<root->key<<" ";

root=root->right;
}

}
node * insertBST(node *root,int value){
	if(root==NULL) {
		node *temp=new node;
		temp->key=value;
		temp->left=temp->right=NULL;
		return temp;
	}
	
	if(root->key<=value) root->right=insertBST(root->right,value);
	else if(root->key>value) root->left=insertBST(root->left,value);
	return root; 
}
int main(){node *tree=NULL;
	cout<<"Enter BST size, followed by values: \n";
int size,value;
cin>>size;
for(int i=0;i<size;++i)
{
	cin>>value;
	tree=insertBST(tree,value);
}
    inorder(tree);
	return 0;
}
