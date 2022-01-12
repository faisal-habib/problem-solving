/*
Problem: https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        if(val < root -> val) root -> left = insertIntoBST(root -> left, val);
        else root -> right = insertIntoBST(root -> right, val);

        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        TreeNode* curr = root, *par = NULL;
        while(true) {
            par = curr;
            if(val < par -> val) {
                curr = curr -> left;
                if(!curr) {
                    par -> left = new TreeNode(val);
                    return root;
                }
            }
            else {
                curr = curr -> right;
                if(!curr) {
                    par -> right = new TreeNode(val);
                    return root;
                }
            }
        }

        return root;
    }
};
