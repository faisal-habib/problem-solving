/*
Problem:
https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1

Resources:
https://www.geeksforgeeks.org/tree-isomorphism-problem/
https://towardsdatascience.com/graph-theory-isomorphic-trees-7d48aa577e46
*/

/**
Time: O(min(m,n)*2) or O(min(m,n)) where m and n are number of nodes in given trees.
*/
// Return True if the given trees are isomotphic. Else return False.
bool isIsomorphic(Node *root1,Node *root2)
{
    if(!root1 && !root2) return true;

    if(!root1 || !root2) return false;

    if(root1->data!=root2->data) return false;

    if ( (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) || (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left)) ) return true;
    return false;
}
