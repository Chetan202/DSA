//Full code == https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
//https://www.youtube.com/watch?v=0GF5Al7LvNQ
class Solution
{
public:
    vector<int> v;
    void solve(int src, vector<int> &vis, vector<int> g[])
    {
        vis[src] = 1;
        v.push_back(src);
        for (auto x : g[src])
        {
            if (!vis[x])
            {
                solve(x, vis, g);
            }
        }
    }

    //Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        v.clear();
        vector<int> vis(V, 0);
        solve(0, vis, adj);
        return v;
    }
};
