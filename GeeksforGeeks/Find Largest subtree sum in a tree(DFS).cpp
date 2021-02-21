/*
References:
https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/
*/

/**
Time: O(n)
*/
int _dfs(Node *root, int &maxSum)
{
    if(!root) return 0;

    int left = _dfs(root->left, maxSum);
    int right = _dfs(root->right, maxSum);

    int currSum = root->data + left + right;
    maxSum = max(maxSumm, currSum);

    // Return current subtree sum to its parent node.
    return currSum;
}

int getMaxSumOfSubtree(Node *root)
{
    int maxSum = 0;
    _dfs(root, maxSum);
    return maxSum;
}
