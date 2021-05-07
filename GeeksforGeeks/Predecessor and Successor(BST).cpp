/*
Problem:
https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#

Resources:
https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
*/

Node *_getMaxVal(Node *root)
{
    if(!root->right) return root;
    return _getMaxVal(root->right);
}

Node *_getMinVal(Node *root)
{
    if(!root->left) return root;
    return _getMinVal(root->left);
}

void _solve(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root) return ;
    if(root->key==key)
    {
        if(root->left) pre = _getMaxVal(root->left);
        if(root->right) suc = _getMinVal(root->right);
    }
    else if(key<root->key)
    {
        suc = root;
        _solve(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        _solve(root->right, pre, suc, key);
    }
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL, suc = NULL;
    _solve(root, pre, suc, key);
}

/**
Approach 2:
Do only an in-order traversal
predecessor will be the max value which is less than the given key
successor will be the min value which is greater than the given key
*/

void _inOrder(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root) return ;

    _inOrder(root->left, pre, suc, key);
    if(key<root->key)
    {
        if(!suc || (suc && suc->key>root->key)) suc = root;
    }
    else if(key>root->key)
    {
        if(!pre || (pre->key<root->key)) pre = root;
    }
    _inOrder(root->right, pre, suc, key);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL, suc = NULL;
    _inOrder(root, pre, suc, key);
}
