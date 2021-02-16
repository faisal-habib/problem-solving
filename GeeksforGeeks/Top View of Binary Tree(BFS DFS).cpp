/*
Problem link:
https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
https://www.hackerrank.com/challenges/tree-top-view/problem

Resources:
https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
https://www.youtube.com/watch?v=c3SAvcjWb1E
*/
/**
approach 1: BFS
*/
vector<int> topView(struct Node *root)
{
    vector<int>output;
    if(!root) return output;

    unordered_map<int,int>vis;
    unordered_map<Node*,int>dis;
    dis[root] = 0;
    vis[0] = root->data; // here key will be distance
    int minDis = 0, mxDis = 0;
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if(curr->left)
        {
            dis[curr->left] = dis[curr] - 1;
            if(!vis[dis[curr->left]]) vis[dis[curr->left]] = curr->left->data;
            minDis = min(minDis, dis[curr->left]);
            q.push(curr->left);
        }

        if(curr->right)
        {
            dis[curr->right] = dis[curr] + 1;
            if(!vis[dis[curr->right]]) vis[dis[curr->right]] = curr->right->data;
            mxDis = max(mxDis, dis[curr->right]);
            q.push(curr->right);
        }
    }

    for(int i=minDis; i<=mxDis; i++) output.push_back(vis[i]);

    return output;
}


/**
approach 2: DFS
*/

void _topView(Node *root, int currDis, int currLevel, map<int, pair<int, int>>&mp)
{
    if(!root) return ;
    if(!mp.count(currDis) || mp[currDis].second>currLevel)
    {
        mp[currDis] = {root->data, currLevel};
    }

    _topView(root->left, currDis-1, currLevel+1, mp);
    _topView(root->right, currDis+1, currLevel+1, mp);
}

vector<int> topView(struct Node *root)
{
    vector<int>output;
    if(!root) return output;

    map<int, pair<int, int>>mp;   // here we'll store pair of node value and its level with respect to the vertical distance from root.
    mp.clear();
    int currDis = 0, currLevel = 0;
    _topView(root, currDis, currLevel, mp);

    for(auto it=mp.begin(); it!=mp.end(); it++) output.push_back(it->second.first);

    return output;
}

