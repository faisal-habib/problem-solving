/*
Problem:
https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
Resources:
https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree/
https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/
*/
/**
Idea is to first find the node and then backtrack to the kth parent.

Time : O(n)
Space : O(n)
*/

void _bfs(Node *root, int node, int ancestor[])
{
    ancestor[root->data] = -1;
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if(curr->left)
        {
            ancestor[curr->left->data] = curr->data;
            q.push(curr->left);
        }
        if(curr->right)
        {
            ancestor[curr->right->data] = curr->data;
            q.push(curr->right);
        }
    }
}

int _getKthAncestor(Node *root, int node, int givenNode, int k)
{
    // nodes are numbered from 1-node
    // find k th node of givenNode
    int ancestor[node+1];
    for(int i=1; i<=node; i++) ancestor[i] = 0;
    _bfs(root, node, ancestor);

    int ancestorNum = 0, kthAncestor;
    while(true)
    {
        kthAncestor = ancestor[givenNode];
        ancestorNum++;
        if(ancestorNum==k || kthAncestor==-1) break;
    }
    return kthAncestor;
}

/** ------------------------------------------------------------------ */

/**
Solution 2: using DFS
Here we don't need extra array
The idea is to first find the given node in the tree, and then backtrack k times to reach to kth ancestor,
once we have reached to the kth parent, we will simply print the node and return NULL.

Time : O(n)
Space : O(n)
*/

Node *_dfs(Node *root, int givenNode, int k)
{
    if(!root) return NULL;

    if(root->data==givenNode && k==0) return root;

    if(k<=0) return NULL;

    Node *left = _dfs(root->left, givenNode, k-1);
    Node *right = _dfs(root->right, givenNode, k-1);

    if(left || right) return root;

    return NULL;
}

int _getKthAncestor(Node *root, int node, int givenNode, int k)
{
    Node *kthAncestor = _dfs(root, givenNode, k);
}
