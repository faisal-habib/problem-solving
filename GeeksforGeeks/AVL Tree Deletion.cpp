/*
Problem link:
https://practice.geeksforgeeks.org/problems/avl-tree-deletion/1

Resources:
https://github.com/faisal-habib/DSA/blob/main/Graph%20%26%20Tree/AVL_Tree.cpp
*/


/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

int _getMinimumValue(Node *root)
{
    if(!root) return INT_MAX;
    if(!root->left) return root->data;

    return _getMinimumValue(root->left);
}

int _getHeight(Node *root)
{
    if(root==NULL) return 0;
    return root->height;
}

int _getBalanceFactor(Node *root)
{
    if(root==NULL) return 0;
    return ( _getHeight(root->left) - _getHeight(root->right) );
}


Node* _leftRotation(Node* root)
{
	if (root == NULL) return root;

	Node* newRootNode = root->right;
	Node* tmpNode = newRootNode->left;

	// performing rotation
	newRootNode->left = root;
	root->right = tmpNode;

	// updating height
	root->height = 1 + max(_getHeight(root->left), _getHeight(root->right));
	newRootNode->height = 1 + max(_getHeight(newRootNode->left), _getHeight(newRootNode->right));

	return newRootNode;
}

Node* _rightRotation(Node* root)
{
	if (root == NULL) return root;

	Node* newRootNode = root->left;
	Node* tmpNode = newRootNode->right;

	// performing rotation
	newRootNode->right = root;
	root->left = tmpNode;

	// updating height
	root->height = 1 + max(_getHeight(root->left), _getHeight(root->right));
	newRootNode->height = 1 + max(_getHeight(newRootNode->left), _getHeight(newRootNode->right));

	return newRootNode;
}

Node* _deleteNodeFromAvlTree(Node* root, int num)
{
    if(!root) return root;

    if(num < root->data) root->left = _deleteNodeFromAvlTree(root->left, num);
    else if(num > root->data) root->right = _deleteNodeFromAvlTree(root->right, num);
    else
    {
        if(!root->left && !root->right)
        {
            delete(root);
            root = NULL;
        }
        else if(root->left && !root->right)
        {
            Node *tmp = root->left;
            delete(root);
            root = tmp;
        }
        else if(!root->left && root->right)
        {
            Node *tmp = root->right;
            delete(root);
            root = tmp;
        }
        else
        {
            int minValOfRightSubTree = _getMinimumValue(root->right);
            root->data = minValOfRightSubTree;
            root->right = _deleteNodeFromAvlTree(root->right, minValOfRightSubTree);
        }
    }

    if(!root) return root;

    // update height & balance factor
    root->height = 1 + max( _getHeight(root->left), _getHeight(root->right) );

    int balanceFactor = _getBalanceFactor(root);

    if(balanceFactor < -1 )
    {
        int balanceFactoreOfRightSubTree = _getBalanceFactor(root->right);

        if (balanceFactoreOfRightSubTree == 1)
		{
			root->right = _rightRotation(root->right);
			return _leftRotation(root);
		}
		else if (balanceFactoreOfRightSubTree == -1)
		{
			return _leftRotation(root);
		}
		else if (balanceFactoreOfRightSubTree == 0)
		{
			return _leftRotation(root);
		}
    }
    else if(balanceFactor > 1 )
    {
        int balanceFactoreOfLeftSubTree = _getBalanceFactor(root->left);

        if (balanceFactoreOfLeftSubTree == 1)
		{
			return _rightRotation(root);
		}
		else if (balanceFactoreOfLeftSubTree == -1)
		{
			root->left = _leftRotation(root->left);
			return _rightRotation(root);
		}
		else if (balanceFactoreOfLeftSubTree == 0)
		{
			return _rightRotation(root);
		}
    }

    return root;
}

Node* deleteNode(Node* root, int data)
{
    return _deleteNodeFromAvlTree(root, data);
}
