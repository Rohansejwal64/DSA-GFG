// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(vector<int> &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
             adj[edge[01]].push_back({edge[0],edge[2]});
            
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans(V,INT_MAX);
        ans[src]=0;
        pq.push({src,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            for(pair<int,int> &v:adj[it.first]){
                if(ans[v.first]>(it.second+v.second)){
                    ans[v.first]=it.second+v.second;
                    pq.push({v.first,ans[v.first]});
            
                
            }
        }
    }
    return ans;
    }
};