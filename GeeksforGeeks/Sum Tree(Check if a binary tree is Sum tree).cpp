/*
Problem link:
https://practice.geeksforgeeks.org/problems/sum-tree/1
Resources:
https://www.techiedelight.com/check-given-binary-tree-sum-tree-not/

Time: O(N)
*/


int _isSumTree(Node *root)
{
    if(root==NULL) return 0;

    if(root->left==NULL && root->right==NULL) return root->data;

    if(root->data==_isSumTree(root->left)+_isSumTree(root->right)) return (2*root->data);

    return INT_MIN;
}

bool isSumTree(Node* root)
{
     return (_isSumTree(root)==INT_MIN?false:true);
}
