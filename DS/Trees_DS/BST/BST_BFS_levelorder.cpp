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

// Function to traverse the tree using BFS approach (level order)

void levelorder(bstnode* root) {
	
	//if tree is empty
	
	if(root == NULL) {
		return ;
	}
	else {
		
		//Maintain a queue for each node 
		
		queue<bstnode*>bfs;
		bfs.push(root);
		
		//while there is at least one discovered node
		
		while(!bfs.empty()) {
			
			bstnode* temp = bfs.front();
			cout<< temp -> data <<" ";
			
			if(temp -> left != NULL){
				bfs.push(temp -> left);
			}
			
			if(temp -> right != NULL){
				bfs.push(temp -> right);
			}
			
			// remove the traversed node from queue
			
			bfs.pop();
		}
	}
	cout<<endl;
}

int main() {
	
	//For faster input and output
	ios_base :: sync_with_stdio (false);
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
	
	levelorder(root);
	
}
