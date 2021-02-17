/*
Problem link:
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Resources:
https://www.geeksforgeeks.org/bottom-view-binary-tree/
*/

/**
approach 1: BFS
*/

vector <int> bottomView(Node *root)
{
   vector<int>v;
   if(!root) return v;

   queue<Node*>q;
   unordered_map<int,int>mp;
   unordered_map<Node*,int>dis;
   q.push(root);
   mp[0] = root->data;
   dis[root] = 0;
   int minDis = 0, maxDis = 0;

   while(!q.empty())
   {
       int qSz = q.size();
       for(int i=1; i<=qSz; i++)
       {
           Node *curr = q.front();
           q.pop();
           if(curr->left)
           {
               q.push(curr->left);
               int d = dis[curr] - 1;
               dis[curr->left] = d;
               mp[d] = curr->left->data;
               minDis = minDis<d?minDis:d;
           }
           if(curr->right)
           {
               q.push(curr->right);
               int d = dis[curr] + 1;
               dis[curr->right] = d;
               mp[d] = curr->right->data;
               maxDis = maxDis>d?maxDis:d;
           }
       }
   }

   for(int i=minDis; i<=maxDis; i++) v.push_back(mp[i]);
   return v;
}



/**
approach 2: DFS
*/

void _bottomView(Node *root, int currDis, int currLevel, unordered_map<Node*,int>&level, unordered_map<int,Node*>&horizontalDis, int &minDis, int &maxDis)
{
    if(!root) return;

    minDis = minDis<currDis?minDis:currDis;
    maxDis = maxDis>currDis?maxDis:currDis;
    level[root] = currLevel;

    if(horizontalDis.find(currDis)==horizontalDis.end())
    {
        horizontalDis[currDis] = root;
    }
    else if(level[horizontalDis[currDis]]<=currLevel)
    {
        horizontalDis[currDis] = root;
    }

    _bottomView(root->left, currDis-1, currLevel+1, level, horizontalDis, minDis, maxDis);
    _bottomView(root->right, currDis+1, currLevel+1, level, horizontalDis, minDis, maxDis);
}

vector <int> bottomView(Node *root)
{
    vector<int>v;
    if(!root) return v;

    unordered_map<Node*,int>level;
    unordered_map<int,Node*>horizontalDis;
    int currLevel = 0, currDis = 0, minDis = 0, maxDis = 0;
    _bottomView(root, currDis, currLevel, level, horizontalDis, minDis, maxDis);

    for(int i=minDis; i<=maxDis; i++) v.push_back(horizontalDis[i]->data);
    return v;
}
