/*
Problem:
https://leetcode.com/problems/maximum-depth-of-binary-tree/
References:
https://www.enjoyalgorithms.com/blog/find-height-of-a-binary-tree
https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
*/

/*
Solution 1: 
using DFS
Time: O(N)
*/
class Solution {
public:
    int _getTreeHeight(TreeNode *root) {
        if(!root) return 0;
        int lh = _getTreeHeight(root->left);
        int rh = _getTreeHeight(root->right);
        
        int h = lh>rh ? (lh+1) : (rh+1);
        return h;
    }
    int maxDepth(TreeNode* root) {
        return _getTreeHeight(root);
    }
};

/*
Solution 2: 
using BFS
Time: O(N)
*/

class Solution {
public:
    int _bfs(TreeNode *root) {
        if (!root) return 0;
        
        int maxDepth = 0;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            maxDepth++;
            int currQueueSz = q.size();
            for(int i = 0; i < currQueueSz; i++) {
                TreeNode *currNode = q.front();
                q.pop();
                
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
            }
        }
        
        return maxDepth;
    }
    int maxDepth(TreeNode* root) {
        return _bfs(root);
    }
};