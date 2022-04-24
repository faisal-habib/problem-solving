class BSTIterator {
public:
    stack<TreeNode*> stk;

    void _addAllLeftNodesToStack(TreeNode *curr) {
        while(curr) {
            stk.push(curr);
            curr = curr->left;
        }
    }

    BSTIterator(TreeNode* root) {
        _addAllLeftNodesToStack(root);
    }

    int next() {
        TreeNode *top = stk.top();
        stk.pop();
        _addAllLeftNodesToStack(top->right);
        return top->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};
