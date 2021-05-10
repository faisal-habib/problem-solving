/*
Problem:
https://leetcode.com/problems/balance-a-binary-search-tree/
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

    TreeNode *_createBalancedBstFromSortedArray(vector<TreeNode*>&vec, int leftInd, int rightInd) {
        if(leftInd > rightInd) return NULL;

        int mid = leftInd + (rightInd - leftInd)/2;
        TreeNode *root = vec[mid];
        root->left = _createBalancedBstFromSortedArray(vec, leftInd, mid-1);
        root->right = _createBalancedBstFromSortedArray(vec, mid+1, rightInd);

        return root;
    }

    void _inOrder(TreeNode *root, vector<TreeNode*>&vec) {
        if(!root) return ;

        _inOrder(root->left, vec);
        vec.push_back(root);
        _inOrder(root->right, vec);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>vec;
        _inOrder(root, vec);

        // similar as prob 108. Convert Sorted Array to Binary Search Tree
        return _createBalancedBstFromSortedArray(vec, 0, vec.size()-1);
    }
};
