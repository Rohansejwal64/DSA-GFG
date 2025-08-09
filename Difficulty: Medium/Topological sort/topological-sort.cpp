class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indeg(V,0);
        vector<int> ans;
        for(vector<int> &edge:edges){
            int u=edge[0];
            int v=edge[1];
            indeg[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            
            q.pop();
            for(int &v: adj[u]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
            
        }
        return ans;
    }
};