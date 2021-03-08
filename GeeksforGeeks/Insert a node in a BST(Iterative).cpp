/*
Problem:
https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

Resources:
https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
*/

Node *_insertIntoBST(Node *root, int val)
{
    Node *tmp = new Node(val);
    if(!root) return tmp;

    Node *curr = root, *parent = NULL;
    while(true)
    {

        if(val<curr->data)
        {
            if(curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = tmp;
                break;
            }
        }
        else if(val>curr->data)
        {
            if(curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = tmp;
                break;
            }
        }
        else break;
    }
    return root;
}


// The function returns the root of the BST (currently rooted at 'root')
// after inserting a new Node with value 'Key' into it.

Node* insert(Node* root, int Key)
{
    root = _insertIntoBST(root, Key);
    return root;
}
