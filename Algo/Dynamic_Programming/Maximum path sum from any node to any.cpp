#include<bits/stdc++.h>
using namespace std;

//Time Complexity O(N)

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;

	Node(int x) {
		data = x;
		left = right = NULL;
	}
};


int pathsum(TreeNode* root, int &answer) {

	if (root == NULL) {
		return 0;
	}

	int ltsum = pathsum(root -> left, answer);
	int rtsum = pathsum(root -> right, answer);

	int temp = max(max(ltsum, rtsum) + root -> value, root -> value);
	int solution = max(temp, ltsum + rtsum + root -> value);

	answer = max(answer, solution);

	return temp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//Root is a pointer of type struct TreeNode which will point to root node of the tree

	int answer = INT_MIN;

	int max_at_root = pathsum(Root, &answer);

	cout << answer << endl;

	return 0;

}