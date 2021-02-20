/*
References:
https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/
https://www.geeksforgeeks.org/check-given-graph-tree/
https://cp-algorithms.com/graph/finding-cycle.html
*/

/**
A graph will be tree iff
1. it doesn't contain any cycle
2. all nodes are connected

to check connectivity-
- at first, consider parent of every node is -1
- traverse nodes of the graph using bfs
- if the graph is connected, then after running bfs, there'll be max 1 node whose parent will be -1 (it's the root node)
- if the graph is not connected, then after running bfs, there'll be more than 1 node whose parent will be -1

*/
#include<bits/stdc++.h>
using namespace std;
#define MX_NODE 100
#define white 0
#define black 1

int node, edge;
vector<int>adj[MX_NODE];
bool vis[MX_NODE];
int parent[MX_NODE];

/**
Time: O(V+E)
Space: O(V)
V = number of nodes
E = number of edges
*/

bool _bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        int sz = adj[u].size();
        for(int i=0; i<sz; i++)
        {
            int v = adj[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if(v!=parent[u]) return true;
        }
    }
    return false;
}

bool _checkCycle()
{
    for(int i=1; i<=node; i++)
    {
        vis[i] = false;
        parent[i] = -1;
    }
    bool containsCycle = false;
    // considering node number starts from 1
    for(int i=1; i<=node; i++)
    {
        if(!vis[i] && _bfs(i))
        {
            containsCycle = true;
            break;
        }
    }
    if(containsCycle)
    {
        cout<<"Cyclic graph"<<endl;
        return true;
    }
    else
    {
        cout<<"Acyclic graph"<<endl;
        return false;
    }
}
bool _checkConnectivity()
{
    int countRoot = 0;
    for(int i=1; i<=node; i++)
    {
        if(parent[i]==-1)
        {
            countRoot++;
        }
    }
    if(countRoot>1)
    {
        cout<<"Graph is not connected"<<endl;
        return false;
    }
    else
    {
        cout<<"Graph is connected"<<endl;
        return true;
    }
}

int main()
{
    cin>>node>>edge;
    int u, v;
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);    // considering undirected graph
    }

    bool containsCycle = _checkCycle();
    bool connectedGraph = _checkConnectivity();
    if(!containsCycle && connectedGraph) cout<<"------ Given graph is a tree ------"<<endl;
    else cout<<"------ Given graph is not a tree ------"<<endl;

}

/*
// tree example
4 3
1 2
2 3
4 1

// disconnected graph example
6 4
1 2
2 3
3 4
5 6

// cyclic graph example
4 4
1 2
2 3
3 4
1 4
*/
