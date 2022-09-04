// A recursive C++ program to print
// REVERSE level order traversal
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left and right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

/*Function prototypes*/
void printGivenLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

/* Function to print REVERSE
level order traversal a tree*/
void level_order_reverse(node* root)
{
	int h = height(root);
	int i;
	for (i=h; i>=1; i--)
		printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int left_height = height(node->left);
		int right_height = height(node->right);

		if (left_height > right_height)return(left_height + 1);

		else
        return(right_height + 1);

	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

/* Driver code*/
int main()
{
	node *root = newNode(3);
	root->left = newNode(9);
	root->right = newNode(20);
	root->right->left = newNode(15);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;

}

