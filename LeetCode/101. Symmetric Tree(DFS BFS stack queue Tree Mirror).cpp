/**
Solution: 1
Recursive way (using stack)
*/

class Solution {
public:
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;

        if( root1->val==root2->val && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left) ) return true;

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};

/**
Solution: 2
Iterative way (using queue)
*/

class Solution {
public:
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;

        queue<TreeNode*>q;
        q.push(root1);
        q.push(root2);

        while(!q.empty()) {
            TreeNode *curr1 = q.front();
            q.pop();
            TreeNode *curr2 = q.front();
            q.pop();

            if(curr1==NULL && curr2==NULL) continue;
            if(curr1==NULL || curr2==NULL) return false;
            if(curr1->val!=curr2->val) return false;

            q.push(curr1->left);
            q.push(curr2->right);
            q.push(curr1->right);
            q.push(curr2->left);
        }
        return true;

    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};

