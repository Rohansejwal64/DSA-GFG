class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void solve(int u,vector<vector<int>> &adj,vector<bool> &visited, vector<int> &ans){
        queue<int> q;
        q.push(u);
        visited[u]=true;
        ans.push_back(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v: adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    ans.push_back(v);
                    q.push(v);
                    
                }
                    
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        vector<bool> visited(adj.size(),false);
        solve(0,adj,visited,ans);
        return ans;
    }
};