/*
Problem:
https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

References:
https://www.devglan.com/datastructure/distance-between-two-nodes-binary-tree
https://www.youtube.com/watch?v=13m9ZCB8gjw
*/

Node *_getLCA(Node *root, int n1, int n2)
{
    if(!root) return NULL;

    if(root->data==n1 || root->data==n2) return root;

    Node *left = _getLCA(root->left, n1, n2);
    Node *right = _getLCA(root->right, n1, n2);

    if(left && right) return root;
    if(!left && !right) return NULL;

    return (left==NULL ? right : left);
}


//Function to find the lowest common ancestor in a BST.
Node* LCA(Node *root, int n1, int n2)
{
   return _getLCA(root, n1, n2);
}
