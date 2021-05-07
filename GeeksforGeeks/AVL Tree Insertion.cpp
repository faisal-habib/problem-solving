/*
Problem link:
https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1#

Resources:
https://github.com/faisal-habib/DSA/blob/main/Graph%20%26%20Tree/AVL_Tree.cpp
*/

class Solution{
  public:
    Node *_createNode(int val)
    {
        Node *newNode = new Node(val);

        return newNode;
    }

    int _getHeight(Node *root)
    {
        if(root==NULL) return 0;
        return root->height;
    }

    int _getBalanceFactor(Node *root)
    {
        if(root==NULL) return 0;

        return (_getHeight(root->left) - _getHeight(root->right));
    }

    Node *_leftRotation(Node *root)
    {
        Node *newRoot = root->right;
        Node *tmpNode = newRoot->left;

        // performing rotation
        newRoot->left = root;
        root->right = tmpNode;

        // updating height
        root->height = 1 + max(_getHeight(root->left), _getHeight(root->right));
        newRoot->height = 1 + max(_getHeight(newRoot->left), _getHeight(newRoot->right));

        return newRoot;
    }

    Node *_rightRotation(Node *root)
    {
        Node *newRoot = root->left;
        Node *tmpNode = newRoot->right;

        // performing rotation
        newRoot->right = root;
        root->left = tmpNode;

        // updating height
        root->height = 1 + max(_getHeight(root->left), _getHeight(root->right));
        newRoot->height = 1 + max(_getHeight(newRoot->left), _getHeight(newRoot->right));

        return newRoot;
    }

    Node *_insertIntoAvlTree(Node *root, int num)
    {
        if(root==NULL) return _createNode(num);
        else if(num < root->data) root->left = _insertIntoAvlTree(root->left, num);
        else if(num > root->data) root->right = _insertIntoAvlTree(root->right, num);
        else return root;

        root->height = 1 + max(_getHeight(root->left), _getHeight(root->right));

        int balanceFactor = _getBalanceFactor(root);

        if(balanceFactor > 1)
        {
            // L-L
            if(num < root->left->data) return _rightRotation(root);
            // L-R
            else if(num > root->left->data)
            {
                root->left = _leftRotation(root->left);
                return _rightRotation(root);
            }
        }
        else if(balanceFactor < -1)
        {
            // R-R
            if(num > root->right->data) return _leftRotation(root);
            // R-L
            else if(num < root->right->data)
            {
                root->right = _rightRotation(root->right);
                return _leftRotation(root);
            }
        }

        return root;
    }

    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        return _insertIntoAvlTree(node, data);
    }
};
