#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	
	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		
	}
};

node* buildTree(node * &root){
	// cout<<"enter the root node"<<endl;
	int data;
	cin>>data;
	root = new node(data);
	
	if(data == -1) return NULL;
	
	// cout<<"enter left child data of "<<data<<endl;
	root->left = buildTree(root->left);
	// cout<<"enter right child data of "<<data<<endl;
	root->right = buildTree(root->right);
	
	return root;
}

void inorder(node* root , vector<int>&a){
	if(root==NULL) return ;
	inorder(root->left,a);
	a.push_back(root->data);
	inorder(root->right,a);
}




int main(){
	node* root = NULL;
	root = buildTree(root);
	vector<int>a;
	
	inorder(root,a);
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	
	
	
}



/*
10
20
40
-1
-1
50
-1
-1
30
60
-1
-1
-1
*/
