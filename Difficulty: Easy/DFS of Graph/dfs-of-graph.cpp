class Solution {
  public:
  void solve(int u,vector<vector<int>>& adj,vector<bool> &visited,vector<int> &ans){
      if(visited[u]==true) return;
      visited[u]=true;
      ans.push_back(u);
      for(int &v:adj[u]){
          solve(v,adj,visited,ans);
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        vector<bool> visited(adj.size(),false);
        solve(0,adj,visited,ans);
        return ans;
    }
};