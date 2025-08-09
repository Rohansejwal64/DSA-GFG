
class Solution {
  public:
  void dfs(vector<vector<int>> &adj,vector<bool> &visited,int u,vector<int> &path){
      
    visited[u]=true;
    path.push_back(u);
    for(int &v: adj[u]){
        if(visited[v]==false){
            dfs(adj,visited,v,path);
        }
    }
}
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(vector<int> &edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> ans;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int> path;
                dfs(adj,visited,i,path);
                ans.push_back(path);
            }
        }
        return ans;
    }
};
