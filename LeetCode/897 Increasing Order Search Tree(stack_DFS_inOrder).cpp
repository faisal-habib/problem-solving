class Solution {
public:
    void _inOrder(TreeNode *curr, TreeNode *&tempRoot) {
        if (!curr) return ;
        _inOrder(curr->left, tempRoot);
        tempRoot->right = new TreeNode(curr->val);
        tempRoot = tempRoot->right;
        _inOrder(curr->right, tempRoot);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *newTreeRoot = new TreeNode(0);
        TreeNode *temp = newTreeRoot;
        _inOrder(root, temp);
        return newTreeRoot->right;
    }
};


/*
class Solution {
public:
    void _inOrder(TreeNode *curr, vector<int> &allNodes) {
        if (!curr) return ;
        _inOrder(curr->left, allNodes);
        allNodes.push_back(curr->val);
        _inOrder(curr->right, allNodes);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> allNodes;
        TreeNode *newTreeRoot = NULL;
        TreeNode *currNode = NULL;
        _inOrder(root, allNodes);

        for(auto currVal : allNodes) {
            if (!newTreeRoot) {
                newTreeRoot = new TreeNode(currVal);
                currNode = newTreeRoot;
            }
            else {
                currNode->right = new TreeNode(currVal);;
                currNode = currNode->right;
            }
        }
        return newTreeRoot;
    }
};
*/

/*
class Solution {
public:
    TreeNode *_insertIntoBst(TreeNode *root, int num) {
        if (!root) {
            root = new TreeNode(num);
        }
        else root->right = _insertIntoBst(root->right, num);    // we'll need to insert into the right only

        return root;
    }

    void _inOrder(TreeNode *curr, TreeNode *&newTreeRoot) {
        if (!curr) return ;
        _inOrder(curr->left, newTreeRoot);
        newTreeRoot = _insertIntoBst(newTreeRoot, curr->val);
        _inOrder(curr->right, newTreeRoot);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *newTreeRoot = NULL;
        _inOrder(root, newTreeRoot);
        return newTreeRoot;
    }
};
*/
