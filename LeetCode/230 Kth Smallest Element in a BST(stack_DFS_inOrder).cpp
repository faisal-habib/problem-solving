class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int kSmallestValue;
        stack<TreeNode*> stk;
        TreeNode *curr = root;

        while(curr || !stk.empty()) {
            while(curr) {
                stk.push(curr);
                curr = curr->left;
            }
            k--;
            curr = stk.top();
            if (k == 0) {
                kSmallestValue = curr->val;
                break;
            }
            stk.pop();
            curr = curr->right;
        }
        return kSmallestValue;
    }
};

/*
class Solution {
public:
    void _inOrder(TreeNode *root, int &k, int &kSmallestValue) {
        if (!root) return ;
        _inOrder(root->left, k, kSmallestValue);
        k--;
        if (k == 0) {
            kSmallestValue = root->val;
            return ;
        }
        _inOrder(root->right, k, kSmallestValue);
    }

    int kthSmallest(TreeNode* root, int k) {
        int kSmallestValue;
        _inOrder(root, k, kSmallestValue);
        return kSmallestValue;
    }
};
*/
