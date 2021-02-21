/*
Problem:
https://leetcode.com/problems/house-robber-iii/
References:
https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
*/

/**
Solution 1:
Using pair or structure
Time: O(N)
*/

typedef struct
{
    int take, skip;
}Info;

Info _go(Node *root)
{
    if(!root) return Info{0,0};

    Info left = _go(root->left);
    Info right = _go(root->right);

    int takeCurr = root->data + left.skip + right.skip;
    int skipCurr = max(left.take, left.skip) + max(right.take, right.skip);

    return Info{takeCurr, skipCurr};
}

int _getMaxSum(Node *root)
{
    Info ans = _go(root);
    return max(ans.take, ans.skip);
}

/** ------------------------------------------------------------------------------------- */

/**
Solution 2:
Using Map
*/

int _getSumOfGrandChildren(TreeNode *root, unordered_map<TreeNode*,int>&mp)
{
    int sum = 0;
    if(root->left)
    {
        sum+= _go(root->left->left, mp) + _go(root->left->right, mp);
    }
    if(root->right)
    {
        sum+= _go(root->right->left, mp) + _go(root->right->right, mp);
    }
    return sum;
}

int _go(TreeNode *root, unordered_map<TreeNode*,int>&mp)
{
    if(!root)
        return 0;
    if(mp[root])
        return mp[root];

    int takeCurr = root->val + _getSumOfGrandChildren(root, mp);
    int skipCurr = _go(root->left, mp) + _go(root->right, mp);

    return ( mp[root] = max(takeCurr, skipCurr) );
}

int _getMaxSum(TreeNode *root)
{
    unordered_map<TreeNode*,int>mp;
    return _go(root, mp);
}

