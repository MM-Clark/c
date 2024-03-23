#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "bstpractice.h"


struct Node
{
	int data; 
	struct Node* left;
	struct Node* right;
};
//declare as static so no code outside source can access is
static Node *root;
//prototype this function so createTree can call it
static void clearTree(Node *T);

//init tree to empty
void createTree()
{
	clearTree(root);
	root = NULL;
	return;
}

//perform recursive traversal of tree destroying all nodes static so cannot be declared from outside
static void clearTree(Node *T)
{
	if(T==NULL)
		return;
	if(T->left != NULL)
		clearTree(T->left);//clear left subtree
	if(T->right != NULL)
		clearTree(T->right);//clear right subtree
	free(T);
	return;
}

//return TRUE if tree is empty
int isEmpty()
{
	return(root==NULL);
}

//duplicates a node in the tree; used to allow returning a complete structure from the tree without giving access into the tree through the pointers.
static Node *dupNode(Node * T)
{
	Node *dupNode;
	dupNode = (Node *)malloc(sizeof(Node));
	*dupNode = *T;
	dupNode->left = NULL; //SET POINTERS TO NULL
	dupNode->right = NULL;
	return dupNode;
}

struct Node* createNode(int value)
{
	//allocate memory for new Node
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	//check if mem alloc successful
	if(newNode != NULL)
	{
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
	}

	return newNode;
}

struct Node* insertNode(struct Node* root, int value)
{
	//if tree is empty create a new node
	if(root == NULL)
		return createNode(value);

	//if the value is less than the root's data, recursively move down the left subtree
	if(value < root->data)
		root->left = insertNode(root->left, value);
	//if the value is greater than the root's data, recursively move down the right subtree
	if(value > root->data)
		root->right = insertNode(root->right, value);

	//return modified root
	return root;
}


//MAKE A FUNC FOR INSERTION!!!!!!!!!!!!!!!!!!!!

void printPreorder(struct Node* root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printInorder(struct Node* root)
{
	if(root != NULL)
	{
		printInorder(root->left);
		printf("%d ", root->data);
		printInorder(root->right);
	}
}

void printPostorder(struct Node* root)
{
	if(root != NULL)
	{
		printPostorder(root->left);
		printPostorder(root->right);
		printf("%d ", root->data);
	}
}

//Function to free the memory allocated for the binary tree
void freeTree(struct Node* root)
{
	if(root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}
