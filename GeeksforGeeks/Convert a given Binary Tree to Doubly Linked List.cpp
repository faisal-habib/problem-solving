/*
Problem:
https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

Resources:
https://www.youtube.com/watch?v=FsxTX7-yhOw

https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
https://www.educative.io/m/convert-binary-tree-to-doubly-linked-list

*/


void _binaryTreeToDLL(Node *root, Node *&head, Node *&prev)
{
    if(root==NULL) return ;

    _binaryTreeToDLL(root->left, head, prev);

    if(prev==NULL)
    {
        head = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
    }

    prev = root;

    _binaryTreeToDLL(root->right, head, prev);
}

Node *bToDLL(Node *root)
{
    if(root==NULL) return root;

    Node *head = NULL, *prev = NULL;
    _binaryTreeToDLL(root, head, prev);

    return head;
}
