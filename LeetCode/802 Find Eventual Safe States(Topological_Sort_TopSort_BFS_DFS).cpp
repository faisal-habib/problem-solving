class Solution {
public:
	void BuildReverseGraph(int &totalNodes, vector<vector<int>> &graph, vector<int> adj[], vector<int> &indegree) {
		for(int i = 0; i < totalNodes; i++) {
			for(auto nextNode : graph[i]) {
				adj[nextNode].push_back(i);
				indegree[i]++;
			}
		}
	}
	
	void BFS(vector<int> adj[], vector<int> &indegree, vector<int> &allSafeNodes, vector<bool> &visited, int &source) {
		queue<int> q;
		q.push(source);
		
		while(!q.empty()) {
			int currNode = q.front();
			q.pop();
			visited[currNode] = true;
			allSafeNodes.push_back(currNode);
			
			for(auto nextNode : adj[currNode]) {
				if (indegree[nextNode] != 0) {
					indegree[nextNode]--;
					if (indegree[nextNode] == 0) {
						q.push(nextNode);
					}
				}
			}
		}
	}
	
	void TopologicalSort(int &totalNodes, vector<int> adj[], vector<int> &indegree, vector<int> &allSafeNodes) {
		vector<bool> visited(totalNodes, false);
		for(int i = 0; i < totalNodes; i++) {
			if (indegree[i] == 0 && visited[i] == false) {
				BFS(adj, indegree, allSafeNodes, visited, i);
			}
		}
	}
	
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int totalNodes = graph.size();
		vector<int> allSafeNodes;
		vector<int> adj[totalNodes];
		vector<int> indegree(totalNodes, 0);
		
		BuildReverseGraph(totalNodes, graph, adj, indegree);
		TopologicalSort(totalNodes, adj, indegree, allSafeNodes);
		sort(allSafeNodes.begin(), allSafeNodes.end());
		
		return allSafeNodes;
    }
};