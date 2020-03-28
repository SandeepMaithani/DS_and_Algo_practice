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

// Function to search an element in a tree.

bool search(bstnode* root, int data) {
	if(root == NULL) {
		return false;
	}
	
	else if(root -> data == data) {
		return true;
	}
	
	else if(data <= root -> data) {
		return (search(root -> left,data));
	}
	else return (search(root -> right,data));
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie(NULL);
	
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
	
	int x;
	
	cout<<"Enter no to be searched :- "<<endl;
	cin>>x;
	
	if(search(root,x) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
	
	
	return 0;
}
