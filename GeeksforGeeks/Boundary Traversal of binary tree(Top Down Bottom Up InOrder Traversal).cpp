/*
Problem:
https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
Resources:
https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
*/

/**
Time: O(n), where n is the number of nodes in binary tree.
*/

vector<int>boundary;

void _leafTraversal(Node *root)
{
    if(!root) return ;

    _leafTraversal(root->left);

    if(!root->left && !root->right)
    {
        boundary.push_back(root->data);
    }

    _leafTraversal(root->right);
}

// print all left boundary nodes, except a leaf node in top-down manner
void _leftBoundaryTraversal(Node *root)
{
    if(!root) return ;

    if(root->left)
    {
        boundary.push_back(root->data);
        _leftBoundaryTraversal(root->left);
    }
    else if(root->right)
    {
        boundary.push_back(root->data);
        _leftBoundaryTraversal(root->right);
    }
}

// print all right boundary nodes, except a leaf node in bottom-up manner(calling right first)
void _rightBoundaryTraversal(Node *root)
{
    if(!root) return ;

    if(root->right)
    {
        _rightBoundaryTraversal(root->right);
        boundary.push_back(root->data);
    }
    else if(root->left)
    {
        _rightBoundaryTraversal(root->left);
        boundary.push_back(root->data);
    }
}
void _boundaryTraversal(Node *root)
{
    if(!root) return ;

    boundary.push_back(root->data);

    _leftBoundaryTraversal(root->left);

    _leafTraversal(root);

    _rightBoundaryTraversal(root->right);
}


vector <int> printBoundary(Node *root)
{
    boundary.clear();
    _boundaryTraversal(root);
    return boundary;
}
