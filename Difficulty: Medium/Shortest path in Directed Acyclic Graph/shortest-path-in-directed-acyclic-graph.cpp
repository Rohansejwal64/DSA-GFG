// User function Template for C++
class Solution {
  public:
  void dfs(vector<vector<pair<int,int>>> &adj,vector<bool> &visited, stack<int> &st,int u){
      visited[u]=true;
      for(pair<int,int> &p:adj[u]){
          if(!visited[p.first]) dfs(adj,visited,st,p.first);
      }
      st.push(u);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(vector<int> &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        vector<bool> visited(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,st,i);
            }
        }
        vector<int> ans(V,-1);
        ans[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            int d=ans[node];
            if(d!=-1){
                for(pair <int,int> &p:adj[node]){
                    int nd=d+p.second;
                    if(ans[p.first]==-1) ans[p.first]=nd;
                    else{
                        ans[p.first]=min(nd,ans[p.first]);
                    }
                }
            }
        }
        return ans;
    }
};
