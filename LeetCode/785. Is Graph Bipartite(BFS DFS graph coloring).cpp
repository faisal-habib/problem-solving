/**
If a graph is bipartite then
- graph can be colored using 2 colors so that, no 2 adjacent nodes will be same color.
  That means, it will Bicolorable graphs
- vertices can be divided into two disjoint sets so that every edge connects two vertices from different sets
  (i.e. there are no edges which connect vertices from the same set)
- a graph is bipartite if and only if all its cycles have even length

Resources:
https://cp-algorithms.com/graph/bipartite-check.html
https://www.educative.io/edpresso/what-is-a-bipartite-graph
*/

/**
Solution 1:
Using BFS (queue)
Time: O(V+E)
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int color[101];
        for(int i=0; i<101; i++) color[i] = -1;
        int node = graph.size();
        bool bipartite = true, notBipartite = false;
        queue<int>q;
        for(int i=0; i<node; i++) {
            if(color[i]==-1) {
                q.push(i);
                color[i] = 0;

                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    int sz = graph[u].size();

                    for(int j=0; j<sz; j++) {
                        int v = graph[u][j];
                        if(color[v]==-1) {
                            color[v] = color[u]^1;
                            q.push(v);
                        }
                        else if(color[u]==color[v]) return notBipartite;
                    }
                }
            }
        }
        return bipartite;
    }
};

/**
Solution 2:
Using DFS
*/

class Solution {
public:
    bool isBipartite(int u, int uColor, vector<vector<int>>& graph, int color[]) {
        color[u] = uColor;
        int sz = graph[u].size();

        for(int i=0 ; i<sz; i++) {
            int v= graph[u][i];
            if(color[v]==-1) {
                color[v] = color[u]^1;
                if(!isBipartite(v, color[v], graph, color)) return false;
            }
            else if(color[v]==color[u]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int color[101];
        for(int i=0; i<101; i++) color[i] = -1;
        int node = graph.size();
        bool bipartite = true, notBipartite = false;

        for(int i=0; i<node; i++) {
            if(color[i]==-1 && !isBipartite(i, 1, graph, color)) return notBipartite;
        }
        return bipartite;
    }
};
