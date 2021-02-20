/*
References:
https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
https://www.geeksforgeeks.org/check-given-graph-tree/
https://cp-algorithms.com/graph/finding-cycle.html
*/

/**
A graph will be tree iff
1. it doesn't contain any cycle
2. all nodes are connected

to check connectivity, we'll start traversing graph from first node(dfs).
if all nodes can be traversed from 1st node, then graph is connected.
*/
#include<bits/stdc++.h>
using namespace std;
#define MX_NODE 100
#define white 0
#define black 1

int node, edge;
vector<int>adj[MX_NODE];
bool vis[MX_NODE];

/**
Time:  O(V+E)
Space: O(V)
V = number of nodes
E = number of edges
*/
bool _dfs(int u, int par)
{
    vis[u] = true;
    int sz = adj[u].size();
    for(int i=0; i<sz; i++)
    {
        int v = adj[u][i];

        if(!vis[v])
        {
            if(_dfs(v, u)) return true;
        }
        else if(v!=par) return true;
    }
    return false;
}
bool _checkCycle()
{
    for(int i=1; i<=node; i++)
    {
        vis[i] = false;
    }
    bool containsCycle = _dfs(1, -1);    // considering node number starts from 1
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
    // check if all nodes were visited
    for(int i=1; i<=node; i++)
    {
        if(!vis[i])
        {
            cout<<"Graph is not connected"<<endl;
            return false;
        }
    }
    cout<<"Graph is connected"<<endl;
    return true;
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
    if(!containsCycle && connectedGraph) cout<<"Given graph is a tree"<<endl;
    else cout<<"Given graph is not a tree"<<endl;

}

/*
// tree example
4 3
1 2
2 3
1 4

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
