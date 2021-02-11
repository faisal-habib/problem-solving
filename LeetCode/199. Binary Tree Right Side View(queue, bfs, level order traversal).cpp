class Solution {
public:
    vector<int>_getRightView(TreeNode *root) {
        vector<int>output;
        if(root==NULL) return output;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int qSz = q.size();
            for(int i=1; i<=qSz; i++) {
                TreeNode *curr = q.front();
                q.pop();

                if(i==qSz) output.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return output;
    }
    vector<int> rightSideView(TreeNode* root) {
        return _getRightView(root);
    }
};
