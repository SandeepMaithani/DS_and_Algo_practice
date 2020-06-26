#include<bits/stdc++.h>
using namespace std;

//Time complexity O(n) 


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

int diameter(TreeNode* Root, int &answer) {

	if (Root == NULL) {
		return 0;
	}

	int ltdia = diameter(Root -> left, answer);
	int rtdia = diameter(Root -> right, answer);

	int temp = max(ltdia, rtdia) + 1;

	int solution = ltdia + rtdia + 1;

	answer = max(answer, solution);

	return temp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//Root is a pointer of type struct TreeNode which will point to root node of the tree

	int answer = INT_MIN;

	int temp = diameter(Root, &answer);

	cout << answer << endl;

	return 0;

}
