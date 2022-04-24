class Solution {
public:
    void _inOrder(TreeNode *currNode, TreeNode *&firstNode, TreeNode *&secondNode, TreeNode *&prevNode) {
        if (!currNode) return ;
        _inOrder(currNode->left, firstNode, secondNode, prevNode);
        if (!firstNode && prevNode->val > currNode->val) {
            firstNode = prevNode;
        }
        if (firstNode && prevNode->val > currNode->val) {
            secondNode = currNode;
        }
        prevNode = currNode;
        _inOrder(currNode->right, firstNode, secondNode, prevNode);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *firstNode = NULL;
        TreeNode *secondNode = NULL;
        TreeNode *prevNode = new TreeNode(INT_MIN);

        _inOrder(root, firstNode, secondNode, prevNode);

        swap(firstNode->val, secondNode->val);
    }
};
