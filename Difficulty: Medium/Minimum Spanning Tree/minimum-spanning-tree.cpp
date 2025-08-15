class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int sum=0;
        vector<vector<pair<int,int>>> adj(V);
        for(vector<int> &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
            
        }
        vector<bool> visited(V,false);
        
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();
            if(visited[node]) continue;
            visited[node]=true;
            sum+=wt;
            for(pair<int,int> p: adj[node]){
                if(!visited[p.first]){
                    pq.push({p.second,p.first});
                }
            }
        }
        return sum;
        
        
    }
};