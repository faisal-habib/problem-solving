/*
Problem link:
https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
*/

class Solution{
    public:
    int _getHeight(Node *root) {
        if(!root) return 0;
        int lh = _getHeight(root->left);
        int rh = _getHeight(root->right);
        int h = lh>rh ? (lh+1) : (rh+1);
        return h;
    }
    int height(struct Node* node){
        return _getHeight(node);
    }
};
