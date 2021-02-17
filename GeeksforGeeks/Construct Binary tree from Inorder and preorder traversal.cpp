/*
Problem:
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
https://practice.geeksforgeeks.org/problems/construct-tree-1/1

Resources:
https://www.techiedelight.com/construct-binary-tree-from-inorder-preorder-traversal/
https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
*/
unordered_map<int,int>inOrderIndex;

Node *_buildBinaryTree(int in[], int currInPos, int inLastInd, int pre[], int &currPrePos)
{
    if(currInPos>inLastInd) return NULL;

    /* Pick current node from Preorder traversal */
    int v = pre[currPrePos++];
    Node *root = new Node(v);
    /* If this node has no children then return */
    if(currInPos==inLastInd) return root;

    /* find the index of this node in Inorder traversal */
    int ind = inOrderIndex[v];
    root->left = _buildBinaryTree(in, currInPos, ind-1, pre, currPrePos);
    root->right = _buildBinaryTree(in, ind+1, inLastInd, pre, currPrePos);

    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    for(int i=0; i<n; i++) inOrderIndex[in[i]] = i;
    int currInPos = 0, currPrePos = 0;
    return _buildBinaryTree(in, currInPos, n-1, pre, currPrePos);
}
