/*
Problem:
https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1

Resources:
https://www.youtube.com/watch?v=FsxTX7-yhOw

https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
https://www.educative.io/m/convert-binary-tree-to-doubly-linked-list

*/

void _binaryTreeToDLL(Node *root, Node *&head, Node *&prev)
{
    if(!root) return ;

    _binaryTreeToDLL(root->left, head, prev);

    if(prev==NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    _binaryTreeToDLL(root->right, head, prev);
}

Node *bTreeToCList(Node *root)
{
    Node *prev = NULL;
    Node *head = NULL;
    _binaryTreeToDLL(root, head, prev);
    // making the DLL circular
    // currently prev node contains the last node of the DLL
    head->left = prev;
    prev->right = head;

    return head;
}
