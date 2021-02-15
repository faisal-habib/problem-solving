/*
Problem link:
https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
*/

vector<int> reverseLevelOrder(Node *root)
{
    vector<int>tree;
    if(root==NULL) return tree;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        tree.push_back(curr->data);

        if(curr->right) q.push(curr->right);
        if(curr->left) q.push(curr->left);
    }
    reverse(tree.begin(), tree.end());
    return tree;
}
