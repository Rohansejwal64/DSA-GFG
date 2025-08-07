class Solution {
  public:
  void dfs(int u,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &st){
      visited[u]=true;
      for(int &v: adj[u]){
          if(!visited[v]){
              dfs(v,adj,visited,st);
          }
      }
      st.push(u);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> ans;
        stack<int> st;
        vector<vector<int>> adj(V);
        for(vector<int> &edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};