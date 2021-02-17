/*
Problem link:
https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
https://leetcode.com/problems/balanced-binary-tree/

Resources:
https://www.youtube.com/watch?v=nOcFiGl5Vy4
*/

/**
Solution 1:
O(N)
*/
int _checkHeightBalance(Node *root)
{
    if(!root) return 0;

    int lh = _checkHeightBalance(root->left);
    int rh = _checkHeightBalance(root->right);

    if(lh==-1 || rh==-1 || abs(lh-rh)>1) return -1;

    return (lh>rh?(lh+1):(rh+1));
}

bool isBalanced(Node *root)
{
    return (_checkHeightBalance(root)==-1?false:true);
}
