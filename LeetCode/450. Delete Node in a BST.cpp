/*
Problem:
https://leetcode.com/problems/delete-node-in-a-bst/

Resources:
https://www.techiedelight.com/deletion-from-bst/
*/

class Solution {
public:
    TreeNode *_getMinNode(TreeNode *root)
    {
        if(!root->left) return root;
        return _getMinNode(root->left);
    }
    TreeNode *_deleteValue(TreeNode *root, int val)
    {
        if(!root) return NULL;

        if(val<root->val)
        {
            root->left = _deleteValue(root->left, val);
        }
        else if(val>root->val)
        {
            root->right = _deleteValue(root->right, val);
        }
        else
        {
            // found the value
            if(!root->left && !root->right)
            {
                delete(root);
                root = NULL;
            }
            else if(!root->left)
            {
                TreeNode *tmp = root;
                root = root->right;
                delete(tmp);
            }
            else if(!root->right)
            {
                TreeNode *tmp = root;
                root = root->left;
                delete(tmp);
            }
            else
            {
                TreeNode *tmp = _getMinNode(root->right);
                root->val = tmp->val;
                // now delete that tmp node from right side of the bst
                root->right = _deleteValue(root->right, tmp->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        return _deleteValue(root, key);
    }
};
