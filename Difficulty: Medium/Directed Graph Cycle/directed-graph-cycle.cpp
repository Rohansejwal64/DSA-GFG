class Solution {
  public:
   bool dfs(int u,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &inrecursion){
       visited[u]=true;
       inrecursion[u]=true;
       for(int &v: adj[u]){
           if(visited[v] && inrecursion[v]) return true;
           if(dfs(v,adj,visited,inrecursion)) return true;
       }
       inrecursion[u]=false;
       return false;
   }
   
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(vector<int> &edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V,false);
        vector<bool> inrecursion(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false && dfs(i,adj,visited,inrecursion)){
                return true;
            }
        }
        return false;
    }
};