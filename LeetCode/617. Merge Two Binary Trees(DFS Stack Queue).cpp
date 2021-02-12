/**
Solution 1:
Recursive way/ DFS

Assume m = min( num. of nodes in first tree, num of nodes in second tree )
Time: O(m)
Space: O(m)
The depth of the recursion tree can go upto m in the case of a skewed tree.
In average case, depth will be O(logm)
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

/**
Solution 2:
Iterative way/ Using stack
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;

        stack<TreeNode*>stk1;
        stack<TreeNode*>stk2;

        stk1.push(root1);
        stk2.push(root2);

        while(!stk1.empty()) {
            TreeNode *curr1 = stk1.top();
            stk1.pop();
            TreeNode *curr2 = stk2.top();
            stk2.pop();

            curr1->val+=curr2->val;

            // as we're using stack, we'll push the right child first, then left child. So left child'll be on top
            if(curr1->right==NULL && curr2->right!=NULL) {
                curr1->right = curr2->right;
            }
            else if(curr1->right!=NULL && curr2->right!=NULL) {
                stk1.push(curr1->right);
                stk2.push(curr2->right);
            }

            if(curr1->left==NULL && curr2->left!=NULL) {
                curr1->left = curr2->left;
            }
            else if(curr1->left!=NULL && curr2->left!=NULL) {
                stk1.push(curr1->left);
                stk2.push(curr2->left);
            }
        }

        return root1;
    }
};

/**
Solution 2:
Iterative way/ Using Queue/ BFS
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;

        queue<TreeNode*>q1;
        queue<TreeNode*>q2;

        q1.push(root1);
        q2.push(root2);

        while(!q1.empty()) {
            TreeNode *curr1 = q1.front();
            q1.pop();
            TreeNode *curr2 = q2.front();
            q2.pop();

            curr1->val+=curr2->val;

            if(curr1->left==NULL && curr2->left!=NULL) {
                curr1->left = curr2->left;
            }
            else if(curr1->left!=NULL && curr2->left!=NULL) {
                q1.push(curr1->left);
                q2.push(curr2->left);
            }

            if(curr1->right==NULL && curr2->right!=NULL) {
                curr1->right = curr2->right;
            }
            else if(curr1->right!=NULL && curr2->right!=NULL) {
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
        }

        return root1;
    }
};


/**
If in problem, it asks for creating a new tree to give output
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return NULL;

        int val = 0;
        if(root1) val = root1->val;
        if(root2) val += root2->val;

        TreeNode *node = new TreeNode(val);

        TreeNode *l1 = NULL, *l2 = NULL, *r1 = NULL, *r2 = NULL;

        if(root1) {
            l1 = root1->left;
            r1 = root1->right;
        }
        if(root2) {
            l2 = root2->left;
            r2 = root2->right;
        }

        node->left = mergeTrees(l1, l2);
        node->right = mergeTrees(r1, r2);

        return node;
    }
};
