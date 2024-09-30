#include<iostream>

using namespace std;
//YAY WASTE OF TIME!!!!
struct BinaryTree
{
    public:
    int data;
    struct BinaryTree *lChild;
    struct BinaryTree *rChild;
    struct BinaryTree *Parent;
};
//Function to create new node
BinaryTree *BinarySearchTree::Insert(struct Node* node, int value)
{
    // If tree doesn't exist
    // create a new node
    if(node == NULL)
    {
        node = new BinaryTree;
        node->data = value;
        node->lChild = NULL;
        node->rChild = NULL;
        node->Parent = NULL;
    }
    // check the right subtree if given
    // value is greater than the node's data
    else if(node->data < value)
    {
        node->rChild = Insert(node->rChild, value);
        node->rChild->Parent = node;
    }
    // Check the left subtree if the given node
    // is smaller than the given node's data
    else
    {
        node->lChild = Insert(node->lChild, value);
        node->lChild->Parent = node;
    }
};
void BinaryTree::preorder(struct Node* node)
{
    // Stop if no node found
    if (node == NULL)
        return;
    //first print data of node
    cout<<node->data;
    //then left subtree
    preorder(node->left);
    //then right
    preorder(node->right);
}
void BinaryTree::inorder(struct Node* node)
{
    if(node == NULL)
        return;
    inorder(node->left);
    cout<<node->data;
    inorder(node->right);
}
void BinaryTree::postorder(struct Node* node)
{
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data;
}
int BinarySearchTree::successor(struct Node* node)
{
    // The successor is the minimum data value
    // of the right subtree
    if(node->rChild != NULL)
    {
        return Min(node->rChild);
    }
}
int BinarySearchTree::predecessor(struct Node* node)
{
    //predecessor is max data value of left subtree
    if (node->lChild != NULL)
    {
        return Max(node->lChild);
    }
}
void deleteDeepest(struct Node* root, struct Node* d_node)
{
    queue<struct Node*> q;
    q.push(root);
    //do level order traversal until last node
    struct Node* temp;
    while (!q.empty()) 
    {
        temp = q.front();
        q.pop();
        if (temp == d_node) 
        {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
        if (temp->left)
        {
            if(temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
Node* deletion(struct Node* root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    queue<struct Node*> q;
    q.push(root);

    struct Node* temp;
    struct Node* key_node = NULL;

    // do level order traversal to find deepest node(temp) and node
    // to be deleted (key_node)
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            key_node = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    if(key_node != NULL)
    {
        int x = temp->data;
        deleteDeepest(root, temp);
        key_node->data = x;
    }
    return root;
}
int main()
{
    BinaryTree root=NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
}