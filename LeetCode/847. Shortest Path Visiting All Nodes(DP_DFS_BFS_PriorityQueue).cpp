/*
Problem link:
https://leetcode.com/problems/shortest-path-visiting-all-nodes/

Resource:
https://leetcode.com/problems/shortest-path-visiting-all-nodes/solution/
*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int graphSz = graph.size();
        if (graphSz == 1) return 0;
        int endingMask = (1 << graphSz) - 1;
        int shotestPathLength = INT_MAX;
        queue<vector<int>> q;
        set<pair<int, int>> st;
        
        for(int i = 0; i < graphSz; i++) {
            vector<int> vec(3, 0);
            int mask = (1 << i);
            int node = i;
            int cost = 0;
            vec[0] = cost;
            vec[1] = node;
            vec[2] = mask;
            
            q.push(vec);
            st.insert({node, mask});
        }
        
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            if (curr[2] == (1 << graphSz) - 1) {
                shotestPathLength = curr[0];
                break;
            }
            
            for(auto adj : graph[curr[1]]) {
                int mask = curr[2] | (1 << adj);
                if (st.find({adj, mask}) == st.end()) {
                    st.insert({adj, mask});
                    vector<int> vec(3, 0);
                    vec[0] = curr[0] + 1;
                    vec[1] = adj;
                    vec[2] = mask;
                    q.push(vec);
                }
            }
        }
        return shotestPathLength;
    }
};