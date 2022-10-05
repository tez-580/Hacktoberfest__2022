// C++ program check whether BST contains
// dead end or not
#include<bits/stdc++.h>
using namespace std;

// A BST node
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new node
Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new Node
with given key in BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);

	/* return the (unchanged) Node pointer */
	return node;
}
void findallNodes(Node* root,map<int,int> &allnodes)
{
	if(root == NULL)
	return ;
	
	allnodes[root->data] = 1;
	findallNodes(root->left,allnodes);
	findallNodes(root->right,allnodes);
}
bool check(Node* root,map<int,int> &allnodes)
{
	if(root == NULL)
	return false;
	
	if(root->left == NULL and root->right == NULL)
	{
		int pre = root->data - 1;
		int next = root->data + 1;

		if(allnodes.find(pre) != allnodes.end() and allnodes.find(next) != allnodes.end())
		return true;
	}
	
	return check(root->left,allnodes) or check(root->right,allnodes);
	
}
bool isDeadEnd(Node *root)
{
	// Base case
if (root == NULL)
		return false ;
	map<int,int> allnodes;
	// adding 0 for handling the exception of node having data = 1
	allnodes[0] = 1;
	findallNodes(root,allnodes);
	
	return check(root,allnodes);
	
}

// Driver program
int main()
{
/*	 8
	/ \
	5 11
	/ \
	2 7
	\
	3
	\
		4 */
	Node *root = NULL;
	root = insert(root, 8);
	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 11);
	root = insert(root, 4);
	if (isDeadEnd(root) == true)
		cout << "Yes " << endl;
	else
		cout << "No " << endl;
	return 0;
}
