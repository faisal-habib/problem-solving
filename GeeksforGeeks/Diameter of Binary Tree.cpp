/*
Problem link:
https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
Resources:
https://www.quora.com/How-do-I-find-the-diameter-of-a-tree
*/

int _getDiameter(Node *root, int &diameter) {
    if(!root) return 0;
    int lh = _getDiameter(root->left, diameter);
    int rh = _getDiameter(root->right, diameter);

    diameter = diameter > (lh+rh+1) ? diameter : (lh+rh+1);

    return ( lh > rh ? (lh+1) : (rh+1) );
}
int diameter(Node* root) {
    int diameter = 0;
    _getDiameter(root, diameter);
    return diameter;
}

