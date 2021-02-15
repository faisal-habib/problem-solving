/*
Problem link:
https://practice.geeksforgeeks.org/problems/level-order-traversal/1
*/


vector<int> levelOrder(Node* node)
{
    vector<int>tree;
    if(!node) return tree;

    queue<Node*>q;
    q.push(node);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        tree.push_back(curr->data);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return tree;
}
