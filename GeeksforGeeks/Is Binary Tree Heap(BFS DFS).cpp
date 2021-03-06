/*
Problem link:
https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#
Resources:
https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-heap/
*/
bool isHeap(Node * tree)
{
    if(!tree) return true;
    priority_queue<Node*>pq;
    pq.push(tree);
    while(!pq.empty())
    {
        Node *curr = pq.top();
        pq.pop();
        if(curr->left)
        {
            if(curr->left->data<=curr->data) pq.push(curr->left);
            else return false;
        }
        if(curr->right)
        {
            if(curr->right->data<=curr->data) pq.push(curr->right);
            else return false;
        }
    }
    return true;
}

/**
DFS
*/
bool _go(Node *tree)
{
    if(!tree) return true;
    if(tree->left==NULL && tree->right==NULL) return true;

    if(tree->left==NULL)
    {
        if(tree->right->data<=tree->data && _go(tree->right)) return true;
        else return false;
    }
    if(tree->right==NULL)
    {
        if(tree->left->data<=tree->data && _go(tree->left)) return true;
        else return false;
    }
    if(tree->left->data<=tree->data && _go(tree->left) && tree->right->data<=tree->data && _go(tree->right)) return true;

    return false;
}
/** ------------------------------------------------ */
bool _go(Node *tree)
{
    if(!tree) return true;
    if(tree->left==NULL && tree->right==NULL) return true;

    if( (tree->left && tree->left->data>tree->data) || (tree->right && tree->right->data>tree->data) ) return false;
    return (_go(tree->left) && _go(tree->right));
}
/** ------------------------------------------------ */
/*You are required to complete this method */
bool isHeap(Node * tree)
{
    return _go(tree);
}
