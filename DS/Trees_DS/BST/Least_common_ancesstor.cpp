#include<bits/stdc++.h>

using namespace std;

//  structure for new BST node

struct bstnode {
	int data;
	bstnode* left;
	bstnode* right;
};

// Function to create new node in heap

bstnode* getnode(int data) {
	bstnode* child = new bstnode();
	child -> data = data;
	child -> left = child -> right = NULL;
	
	return child;		
}

// To insert data in BST, returns address of root node 

bstnode* insert(bstnode* root,int data) {
	
	// when tree is empty
	
	if(root == NULL) {
		root = getnode(data);
	}
	
	// if data to be inserted is lesser, insert in left subtree. 
	
	else if(data <= root -> data) {
		root -> left = insert(root -> left,data);		
	}
	
	// if data to be inserted is greater, insert in right subtree. 
	
	else {
		root -> right = insert(root -> right,data);
	}
	
	return root;
}

bstnode* LCA(bstnode* root,int v1,int v2) {
	
	if(root == NULL) {
		return NULL;
	}
	
	if(root -> data == v1 || root -> data ==v2) {
		return root;
	}
	
	bstnode* left = LCA(root -> left,v1,v2);
	bstnode* right = LCA(root -> right,v1,v2);
	
	if(left != NULL && right != NULL) {
		return root;
	}
	
	if(left == NULL && right ==NULL) {
		return NULL;
	}
	
	if(left != NULL) {
		return left;
	}
	else {
		return right;
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x,y;
	
	//creating an empty tree	
	bstnode* root = NULL;                 
	
	root = insert(root,20);
	root = insert(root,15);
	root = insert(root,25);
	root = insert(root,23);
	root = insert(root,28);
	root = insert(root,21);
	root = insert(root,24);
	root = insert(root,26);
	root = insert(root,30);
	root = insert(root,10);
	root = insert(root,18);
	root = insert(root,4);
	root = insert(root,8);
	root = insert(root,16);
	root = insert(root,19);
	
	cout<<"Enter two number to find their least common ancesstor  "<<endl;
	cin>>x>>y;
	
	bstnode* lca = LCA(root,x,y);
	
	cout<<"Least common ancessotr of "<<x<<" and "<<y<<" is : "<<(lca -> data)<<endl; 
	
	return 0;	
}
