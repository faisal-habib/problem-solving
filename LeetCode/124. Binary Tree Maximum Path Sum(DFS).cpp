/*
Problem:
https://leetcode.com/problems/binary-tree-maximum-path-sum/

Resources:
https://afteracademy.com/blog/maximum-path-sum-in-a-binary-tree
https://www.educative.io/edpresso/the-algorithm-for-the-maximum-sum-in-a-binary-tree?
https://www.youtube.com/watch?v=mOdetMWwtoI
*/

/**
Return max sum of a path which may start and end at any node in the tree (don't have to be root & leaf).

Time Complexity = O(N), where N is the total number of nodes. As we are traversing each node only once.

Space Complexity: O(h), where h is the maximum height of the tree
*/

int MAX(int a,int b)
{
    return ( (a>b)?(a):(b) );
}

int max_sum;

int dfs(struct TreeNode* root)
{
    if(root==NULL) return 0;

    int left_sum=MAX(0,dfs(root->left));
    int right_sum=MAX(0,dfs(root->right));
    int sum=left_sum+right_sum+root->val;
    max_sum=MAX(max_sum,sum);

    return MAX(left_sum,right_sum)+root->val;
}

int maxPathSum(struct TreeNode* root)
{
    max_sum=INT_MIN;
    dfs(root);
    return max_sum;
}
