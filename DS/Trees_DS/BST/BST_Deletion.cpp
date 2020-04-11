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

//Function to find minimum in a tree. 

bstnode* minVal(bstnode* root) {
	
	while(root -> left != NULL) {
		root = root -> left;
	}
	return root;
}

// Function to do inorder(DFS) traversal
//left child right

void inorder(bstnode* root) {
	
	if (root == NULL) {
		return;
	}
	
	inorder(root -> left);
	cout<<root -> data<<" ";
	inorder(root -> right);
	
}


// Function to delete an element from a tree.

bstnode* deletenode(bstnode* root,int data) {
	
	// If tree is empty
	
	if(root == NULL) {
		return root;
	}
	
	//If required node is present at left subtree
	
	else if(data < root -> data) {
		
		root -> left = deletenode(root -> left,data);		
	}
	
	//If required node is present at right subtree
	
	else if(data > root -> data) {
		
		root -> right = deletenode(root -> right,data);
	}
	
	//If we are at the node to be deleted
	
	else {
		
		//case 1 : To delete node with No child
		
		if(root -> left == NULL && root -> right == NULL) {
			delete root;
			root = NULL;
		}
		
		//case 2 : To delete node with One child
		
		else if(root -> right == NULL) {
			bstnode* temp = root;
			root = root -> left;
			delete temp;
		}
		else if(root -> left == NULL) {
			bstnode* temp = root;
			root = root -> right;
			delete temp;
		}
		
		//case 3 : To delete node with Two child
		
		else {
			bstnode* temp = minVal(root -> right);
			root -> data = temp -> data;
			root -> right = deletenode(root -> right,temp -> data);
		}
		
	}
	return root;
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
	
	cout<<"Enter no to be deleted :- "<<endl;
	cin>>x;
	
	cout<<"Tree before Node deletion"<<endl;
	inorder(root);
	
	root = deletenode(root,x);
	
	cout<<"\nTree after Node deletion"<<endl;
	inorder(root);
	
	
	return 0;
}
