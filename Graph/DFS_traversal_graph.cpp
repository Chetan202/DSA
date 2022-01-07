class Solution {

	void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
		storeDfs.push_back(node);
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) {
				dfs(it, vis, adj, storeDfs);
			}
		}
	}


public:
	vector<int>dfsofGraph(int V, vector<int> adj[]) {
		vector<int> storeDfs;
		vector<int> vis(V + 1, 0);
		for (int i = 1; i <= V; i++) {
			if (!vis[i]) {
				dfsofGraph(i, vis, adj, storeDfs)
			}
		}
	}
};