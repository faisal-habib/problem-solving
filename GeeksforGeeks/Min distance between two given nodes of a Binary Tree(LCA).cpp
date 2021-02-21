/*
Problem:
https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

Idea is
- first find the lowest common ancestor of given nodes
- then find the individual distance(d1, d2) to these nodes from the LCA node
- the sum of d1 and d2 will be our final result

References:
https://www.devglan.com/datastructure/distance-between-two-nodes-binary-tree
https://www.youtube.com/watch?v=13m9ZCB8gjw
*/

Node *_getLCA(Node *root, Node *n1, Node *n2)   // O(N)
{
    if(!root) return NULL;

    if(root==n1 || root==n2) return root;

    Node *left = _getLCA(root->left, n1, n2);
    Node *right = _getLCA(root->right, n1, n2);

    if(left && right) return root;
    if(!left && !right) return NULL;

    return (left==NULL?right:left);
}

int _getDistance(Node *root, Node *n1, int distance)
{
    if(!root) return -1;
    if(root==n1) return distance;

    int d = _getDistance(root->left, n1, distance+1);
    if(d!=-1) return d;

    d = _getDistance(root->right, n1, distance+1);
    return d;
}

int _findDistanceBetweenNodes(Node *root, Node *n1, Node *n2)
{
    Node *lca = _getLCA(root, n1, n2);
    int dis1 = _getDistance(lca, n1, 0);
    int dis2 = _getDistance(lca, n2, 0);
    return dis1+dis2;
}

Node *_getNode(Node *root, int data)
{
    if(!root) return NULL;
    if(root->data==data) return root;
    Node *l = _getNode(root->left, data);
    if(l) return l;
    Node *r = _getNode(root->right, data);
    if(r) return r;
}

int findDist(Node* root, int a, int b) {
    Node *n1 = _getNode(root, a);
    Node *n2 = _getNode(root, b);
    int ans = _findDistanceBetweenNodes(root, n1, n2);

    return ans;
}
