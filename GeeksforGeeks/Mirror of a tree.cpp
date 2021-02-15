/*
Problem:
https://leetcode.com/problems/invert-binary-tree/
Resources:
https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
https://www.educative.io/edpresso/how-to-invert-a-binary-tree
*/

/**
Main idea is to swap left & right node.
After inverting a tree, inOrder traversal of the inverted tree will be reverse of inOrder traversal of the main tree.
*/
/**
Approach 1:
Recursive way
*/

Node *_getMirror(Node *root)    // also called _invertTree
{
    if(root==NULL) return NULL;

    Node *l = _getMirror(root->left);
    Node *r = _getMirror(root->right);

    root->left = r;
    root->right = l;

    return root;
}

/**
Approach 2:
Iterative way
*/

Node *_getMirror(Node *root)    // also called _invertTree
{
    if(root==NULL) return NULL;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        swap(curr->left, curr->right);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    return root;
}
