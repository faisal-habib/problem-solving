/**
Time: O(N)
Resources:
https://www.techiedelight.com/construct-binary-tree-from-inorder-preorder-traversal/
https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
*/

class Solution {
public:
    TreeNode *_buildBinaryTree(vector<int>&inorder,int inSt,int inEnd,vector<int>&preorder, int &preInd, unordered_map<int,int>&mp) {
        if(inSt>inEnd) return NULL;

         /* Pick current node from Preorder traversal */
        int val=preorder[preInd++];
        TreeNode *n=new TreeNode(val);

         /* If this node has no children then return */
        if(inSt==inEnd) return n;

        /* Else find the index of this node in Inorder traversal */
        int inPos=mp[val];
        /* Using index of Inorder traversal, construct left & right subtress */
        n->left=_buildBinaryTree(inorder, inSt, inPos-1, preorder, preInd, mp);
        n->right=_buildBinaryTree(inorder, inPos+1, inEnd, preorder, preInd, mp);

        return n;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preInd=0;
        int sz=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<sz;i++) mp[inorder[i]]=i;

        return _buildBinaryTree(inorder, 0, sz-1, preorder, preInd, mp);
    }
};
