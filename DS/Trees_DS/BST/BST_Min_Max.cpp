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

// Function to print tree in a order (left child , parent , right child). 

void printtree(bstnode* root) {
	
	if(root == NULL) {
		return;
	}
	
	printtree(root -> left);
	cout<<root -> data << "  ";
	printtree(root -> right);
}

// Function to find the minimum element of the tree using iterative approach
// Similarly maximum element of the tree can we obtained using iterative approach

int bstmin_itr(bstnode* root) {
	if (root == NULL) {
		cout<<"Tree is empty "<<endl;
		return -1;
	}
	else {
		int minimum;
		while(root -> left != NULL) {
			root = root -> left;
		}
		minimum = root -> data;
		return minimum;
	}	
}

// Function to find the maximum element of the tree using recursion approach
// Similarly minimum element of the tree can we obtained using recursion approach

int bstmax_recrr(bstnode* root) {
	if (root ==NULL) {
		cout<<"Tree is empty "<<endl;
		return -1;
	}
	else if(root -> right == NULL) {
		return root -> data;
	}
	else {
		return bstmax_recrr(root -> right);
	}
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
	
	printtree(root);
	
	cout<<"\nMinimum element in the tree is "<<bstmin_itr(root);
	cout<<"\nMaximum element in the tree is "<<bstmax_recrr(root);
	
	
	return 0;
}
