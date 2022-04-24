/*
Idea:
reverse in-order traversal - a way to visit nodes in descending order, keeping a sum of all values that we have already visited and adding that sum to the node's values as we traverse the tree
 */

// using Iteration with a Stack
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int currTotalSum = 0;
        TreeNode *currNode = root;
        stack<TreeNode*> stk;

        while(!stk.empty() || currNode) {
            //  push all of the nodes along the path to the rightmost leaf onto the stack
            while(currNode) {
                stk.push(currNode);
                currNode = currNode->right;
            }

            //  visit the node on the top of our stack, and consider its left subtree
            currNode = stk.top();
            stk.pop();
            currTotalSum += currNode->val;
            currNode->val = currTotalSum;

            currNode = currNode->left;
        }
        return root;
    }
};

/*
// using recursion
class Solution {
public:
    TreeNode *_reverseInOrder(TreeNode *root, int &currTotalSum) {
        if (root) {
            _reverseInOrder(root->right, currTotalSum);
            currTotalSum += root->val;
            root->val = currTotalSum;
            _reverseInOrder(root->left, currTotalSum);
        }
        return root;
    }

    TreeNode* convertBST(TreeNode* root) {
        int currTotalSum = 0;
        return _reverseInOrder(root, currTotalSum);
    }
};
*/
