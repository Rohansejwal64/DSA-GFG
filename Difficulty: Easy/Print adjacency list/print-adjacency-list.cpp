class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> ans(V);
        for(int i=0;i<edges.size();i++){
            pair<int,int> p=edges[i];
            int u=p.first;
            int v=p.second;
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        return ans;
    }
};