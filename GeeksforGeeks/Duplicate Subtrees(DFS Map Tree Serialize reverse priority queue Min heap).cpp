/*
Problem:
https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1
https://leetcode.com/problems/find-duplicate-subtrees/

Resources:
https://tutorialspoint.dev/data-structure/hashing-data-structure/find-duplicate-subtrees
https://www.includehelp.com/data-structure-tutorial/find-duplicate-subtrees-in-a-given-binary-tree.aspx
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line

priority_queue<int, vector<int>, greater<int>>pq;   // min heap/ reverse pq
string _inOrder(Node *root, unordered_map<string, int>&vis)
{
    if(!root) return "";
    string s = "(";
    s+= _inOrder(root->left, vis);
    s+= to_string(root->data);
    s+= _inOrder(root->right, vis);
    s+= ")";

    if(vis[s]==1) pq.push(root->data);  // here we're checking whether vis[s]==1, because we'll print a duplicate only once
    vis[s]++;
    return s;
}
void printAllDups(Node* root)
{
    unordered_map<string, int>vis;
    _inOrder(root, vis);
    if(pq.empty()) pq.push(-1); // If no duplicate subtree is present in the binary tree print "-1 "
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
