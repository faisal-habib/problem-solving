class Solution {
public:
    int checkHeightBalance(TreeNode *root) {
        if(!root) return 0;

        int l_height=checkHeightBalance(root->left);
        if( l_height==-1 || r_height==-1 ) return -1;

        int r_height=checkHeightBalance(root->right);
        if( l_height==-1 || r_height==-1 ) return -1;
        if( abs(l_height-r_height)>1 ) return -1;

        return ( l_height>r_height?l_height:r_height )+1;
    }
    bool isBalanced(TreeNode* root) {
        if(checkHeightBalance(root)==-1) return false;
        return true;
    }
};
