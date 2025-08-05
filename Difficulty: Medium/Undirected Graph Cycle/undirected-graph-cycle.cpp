class Solution {
  public:
  bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent) {
    visited[u] = true;
    for (int &v : adj[u]) {
        if (v == parent) continue;
        if (visited[v]) return true;
        if (dfs(adj, v, visited, u)) return true;
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<bool> visited(V, false);
    vector<vector<int>> adj(V); // FIX: initialize adjacency list
    
    for (vector<int>& vec : edges) {
        adj[vec[0]].push_back(vec[1]);
        adj[vec[1]].push_back(vec[0]);
    }
    
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfs(adj, i, visited, -1)) {
            return true;
        }
    }
    return false;
}
};