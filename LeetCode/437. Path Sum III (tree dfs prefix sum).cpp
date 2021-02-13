/**
For each node, three searches are needed, and the time cost for each search is the height of the tree, that's O(h).
The worst case, Tree is like Linked List, h == n, O(h) = O(n);
Best case, Tree is Balanced, which means height == logn, O(h) == O(logn);

Since the number of nodes is n, for each node search is O(h) =>
best case: O(nlogn)
worst case: O(nn) -> O(n^2)

*/
class Solution {
public:
    int dfs(TreeNode *r,int targetSum,int curr_sum)
    {
        if(r==NULL) return 0;

        curr_sum+=r->val;

        return (curr_sum==targetSum?1:0)+dfs(r->left,targetSum,curr_sum)+dfs(r->right,targetSum,curr_sum);
    }

    int pathSum(TreeNode* root, int sum)
    {
        if(root==NULL) return 0;

        return dfs(root,sum,0)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};
