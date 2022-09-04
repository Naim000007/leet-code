// C++ program to check if two BSTs
// are identical

#include <iostream>
using namespace std;

// BST node
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// Utility function to create a new Node
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)
		malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

// Function to perform inorder traversal
void inorder(Node* root)
{
	if (root == NULL)
		return;

	inorder(root->left);

	cout << root->data << " ";

	inorder(root->right);
}

bool isSame (Node* root1, Node* root2)
{

	if (root1 == NULL && root2 == NULL)//both are empty
		return true;
	else if (root1 == NULL || root2 == NULL)//1 empty and other one is non empty
		return false;
	else {
		if (root1->data == root2->data && isSame(root1->left, root2->left)
			&& isSame(root1->right, root2->right))
			return true;
		else
			return false;
	}
}

// Driver code
int main()
{
	struct Node* root1 = newNode(5);
	struct Node* root2 = newNode(5);
	root1->left = newNode(3);
	root1->right = newNode(8);
	root1->left->left = newNode(2);
	root1->left->right = newNode(4);

	root2->left = newNode(3);
	root2->right = newNode(8);
	root2->left->left = newNode(2);
	root2->left->right = newNode(4);

	if (isSame(root1, root2))
		cout << "Both BSTs are identical";
	else
		cout << "BSTs are not identical";

	return 0;
}
