/**
Solution 1

Time: O(N)
Space: O(N)
N - Num of nodes in the tree
*/

class Solution {
public:
    typedef struct {
        int rob, skip;
    }RobInfo;

    RobInfo _go(TreeNode *root) {
        if(!root) return RobInfo{0,0};

        RobInfo robLeft = _go(root->left);
        RobInfo robRight = _go(root->right);

        int robCurr = root->val + robLeft.skip + robRight.skip; // if parent is robbed, child can't be robbed
        int skipCurr = max(robLeft.rob, robLeft.skip) + max(robRight.rob, robRight.skip);

        return RobInfo{robCurr, skipCurr};
    }

    int rob(TreeNode* root) {
        RobInfo res = _go(root);
        return max(res.rob, res.skip);
    }
};


/**
Solution 2

Time: O(N)
Space: O(N)
N - Num of nodes in the tree
*/
class Solution {
public:
    unordered_map<TreeNode*, int>mpRobbed, mpNotRobbed;

    int _go(TreeNode *root, bool parentRobbed) {
        if(root==NULL) return 0;

        if(parentRobbed) {
            if(mpRobbed[root]) return mpRobbed[root];

            int result = _go(root->left, false) + _go(root->right, false);
            mpRobbed[root] = result;
            return result;
        }
        else {
            // rob current node
            int rob = root->val + _go(root->left, true) + _go(root->right, true);
            // don't rob current node
            int notRob = _go(root->left, false) + _go(root->right, false);

            int result = rob>notRob ? rob:notRob;
            mpNotRobbed[root] = result;
            return result;
        }
    }

    int rob(TreeNode* root) {
        return _go(root, false);
    }
};
