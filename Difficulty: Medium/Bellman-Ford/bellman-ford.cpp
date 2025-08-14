// User function Template for C++
int m=(int)1e8;
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int> result(V,m);
        result[src]=0;
        for(int i=1;i<=V;i++){
            for(vector<int> &edge:edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(result[u]!=m && result[u]+wt<result[v] ){
                    if(i==V) return {-1};
                    result[v]=result[u]+wt;
                }
            }
        }
        return result;
        
    }
};
