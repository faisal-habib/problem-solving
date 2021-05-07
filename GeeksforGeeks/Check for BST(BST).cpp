/*
Problem:
https://practice.geeksforgeeks.org/problems/check-for-bst/1#

Resources:
https://www.educative.io/edpresso/how-to-check-if-a-binary-tree-is-a-binary-search-tree
*/

class Solution
{
    public:
    bool _isBst(Node *root, int min, int max)
    {
        if(!root) return true;
        if(root->data>min && root->data<max && _isBst(root->left, min, root->data) && _isBst(root->right, root->data, max)) return true;
        return false;
    }
    bool isBST(Node* root)
    {
        int min = INT_MIN, max = INT_MAX;
        return _isBst(root, min, max);
    }
};
