/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}

*/



int height(Node* root)
{
  if (root == NULL) return 0;

  int left = height(root -> left);
  int right = height(root -> right);

  return max(left, right) + 1;
}
