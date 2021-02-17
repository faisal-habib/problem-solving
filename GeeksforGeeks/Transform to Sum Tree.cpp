/*
Problem:
https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

Resources:
https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
https://www.techiedelight.com/inplace-convert-a-tree-sum-tree/
*/

int _makeSumTree(Node *root)
{
    if(!root) return 0;

    int prevData = root->data;

    root->data = _makeSumTree(root->left) + _makeSumTree(root->right);

    return (prevData + root->data);
}

void toSumTree(Node *node)
{
    _makeSumTree(node);
}
