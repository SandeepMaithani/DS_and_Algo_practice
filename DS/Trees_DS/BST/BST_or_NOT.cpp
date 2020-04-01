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

//Function to check wheather a given tree is BST or not

bool isbst(bstnode* root,int min,int max) {
	
	if(root == NULL) {
		return true;
	}
	
	//check wheather the fall between min and max range or not 
	
	if(root -> data <= min || root -> data > max) {
		return false;
	}
	
	//recursively check each subtree is BST or not
	
	return(isbst(root -> left, min, root -> data) && isbst(root -> right, root -> data, max));
}

int main() {
	
	ios_base::sync_with_stdio(false);
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
	
	if(isbst(root, INT_MIN, INT_MAX)) {
		cout<<" Given tree is a Binary search tree "<<endl;
	}
	else {
		cout<<" Given tree is not a Binary search tree "<<endl;		
	}
	
	
	return 0;
}
