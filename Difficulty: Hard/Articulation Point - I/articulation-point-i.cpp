// User function Template for C++

class Solution {
  public:
 void dfs(vector<int> adj[], vector<bool> &visited, vector<int> &tn,
         vector<int> &low, int &timer, vector<int> &ans, int u, int p) {

    visited[u] = true;
    tn[u] = low[u] = timer++;
    int children = 0;   // count dfs children

    for (int &v : adj[u]) {
        if (v == p) continue;

        if (!visited[v]) {
            dfs(adj, visited, tn, low, timer, ans, v, u);
            low[u] = min(low[u], low[v]);
            children++;

            if (low[v] >= tn[u] && p != -1) {
                ans.push_back(u);
            }
        } else {
            low[u] = min(low[u], tn[v]);
        }
    }

    if (p == -1 && children > 1) {
        ans.push_back(u);
    }
}

vector<int> articulationPoints(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> tn(V), low(V);
    vector<int> ans;
    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(adj, visited, tn, low, timer, ans, i, -1);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    if (ans.empty()) return {-1};
    return ans;
}

};