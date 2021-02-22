/**
 Intuition

Suppose we have a unique identifier for subtrees: two subtrees are the same if and only if they have the same id.

Then, for a node with left child id of x and right child id of y, (node.val, x, y) uniquely determines the tree.

Algorithm

If we have seen the triple (node.val, x, y) before, we can use the identifier we've remembered. Otherwise, we'll create a new one.

Time: O(N)
Space: O(N)
*/

class Solution {
public:
    unordered_map<string,int>count, mp;
    int id;
    vector<TreeNode*>output;
    int _dfs(TreeNode *root) {
        if(!root) return 0;
        string s = to_string(root->val) + "," + to_string(_dfs(root->left)) + "," + to_string(_dfs(root->right));

        if(!count[s]) {
            id++;
            mp[s] = id;
        }
        count[s]++;
        if(count[s]==2) output.push_back(root);
        return mp[s];
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        _dfs(root);
        return output;
    }
};
