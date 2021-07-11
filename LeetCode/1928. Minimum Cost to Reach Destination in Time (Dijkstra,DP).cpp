class Solution {
public:
    int cost[1003], time[1003];
    vector< vector<int> > adj[1003];

    int _dijkstra(int &maxTime, int &src, int &dest) {
        priority_queue< vector<int>, vector< vector<int> >, greater< vector<int> > > pq;    // keeping a vector into pq in ascending order

        pq.push({cost[src], time[src], src});

        while(!pq.empty()) {
            vector<int>curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int currTime = curr[1];
            int currNode = curr[2];

            int sz = adj[currNode].size();

            for(int i=0; i<sz; i++) {
                int nextNode = adj[currNode][i][0];
                int timeForNextNode = adj[currNode][i][1];
                int costForNextNode = adj[currNode][i][2];

                if( currTime + timeForNextNode <= maxTime) {
                    // try to reduce cost
                    if( currCost + costForNextNode < cost[nextNode]) {
                        cost[nextNode] = currCost + costForNextNode;
                        time[nextNode] = currTime + timeForNextNode;

                        pq.push({cost[nextNode], time[nextNode], nextNode});
                    }
                    // try to reduce time
                    else if( currTime + timeForNextNode < time[nextNode] ) {
                        time[nextNode] = currTime + timeForNextNode;

                        pq.push({currCost + costForNextNode, time[nextNode], nextNode});
                    }
                }
            }
        }

        return cost[dest];
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int node = passingFees.size();
        int totalEdge = edges.size();

        for(int i=0; i<totalEdge; i++) {
            int u = edges[i][0], v = edges[i][1], t = edges[i][2];
            adj[u].push_back({v, t, passingFees[v]});   // node, time, cost
            adj[v].push_back({u, t, passingFees[u]});
        }

        cost[0] = passingFees[0];
        time[0] = 0;

        for(int i=1; i<node; i++) {
            cost[i] = INT_MAX;
            time[i] = INT_MAX;
        }
        int minCost = _dijkstra(maxTime, 0, node-1);
    }
};

/**
Solution 2: DP
*/

class Solution {
public:
    vector< vector<int> > adj[1003];
    int dp[1003][1003];
    #define MX 10000008

    int _go(int remainingTime, vector<int>& passingFees, int src, int dest) {
        if(remainingTime < 0) return INT_MAX;

        if(src == dest) return passingFees[src];

        if(dp[src][remainingTime] != -1) return dp[src][remainingTime];

        int ans = INT_MAX;
        int sz = adj[src].size();

        for(int i=0; i<sz; i++) {
            int nxt = adj[src][i][0];
            int timeForNextNode = adj[src][i][1];

            if(timeForNextNode <= remainingTime) {
                int res = _go(remainingTime-timeForNextNode, passingFees, nxt, dest);
                ans = min(ans, res);
            }
        }

        if(ans == INT_MAX) dp[src][remainingTime] = ans;
        else dp[src][remainingTime] = ans + passingFees[src];

        return  dp[src][remainingTime];
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int node = passingFees.size();
        int totalEdge = edges.size();
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<totalEdge; i++) {
            int u = edges[i][0], v = edges[i][1], t = edges[i][2];
            adj[u].push_back({v, t});   // node, time
            adj[v].push_back({u, t});
        }

        int minCost = _go(maxTime, passingFees, 0, node-1);

        return minCost >= INT_MAX ? -1 : minCost;
    }
};
