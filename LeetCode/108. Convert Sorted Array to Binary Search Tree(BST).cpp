/*
Problem:
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *_createBalancedBstFromSortedArray(vector<int>&nums,int l,int r) {
        if(l>r) return NULL;

        int m= l + (r-l)/2;

        TreeNode *node= new TreeNode();
        node->val=nums[m];
        node->left=_createBalancedBstFromSortedArray(nums,l,m-1);
        node->right=_createBalancedBstFromSortedArray(nums,m+1,r);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz=nums.size();
        if(!sz) return NULL;

        return _createBalancedBstFromSortedArray(nums,0,sz-1);
    }
};
