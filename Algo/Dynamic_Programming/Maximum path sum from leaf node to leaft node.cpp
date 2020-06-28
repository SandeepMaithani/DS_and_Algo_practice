#include<bits/stdc++.h>
using namespace std;

int leafpath(TreeNode* root, int &answer) {

	if (root == NULL) {
		return 0;
	}

	if (root -> left == NULL && root -> right == NULL) {
		return root -> data;
	}


	if (root -> left == NULL) {
		return (leafpath(root -> right, answer) + root -> data);
	}

	if (root -> right == NULL) {
		return (leafpath(root -> left, answer) + root -> data);
	}


	int ltsum = leafpath(root -> left, answer);
	int rtsum = leafpath(root -> right, answer);


	int temp = max(ltsum, rtsum) + root -> data;


	int solution = ltsum + rtsum + root -> data;

	answer = max(answer, solution);

	return temp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//Root is a pointer of type struct TreeNode which will point to root node of the tree

	int answer = INT_MIN;

	int max_at_root = leafpath(Root, answer);

	cout << answer << endl;

	return 0;

}