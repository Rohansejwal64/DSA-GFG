class Solution {
  public:
  
  bool issafe(int col,vector<int> &color,vector<vector<int>> &edges,int node){
      for(auto &p: edges){
          int u = p[0];
          int v = p[1];
          if(u==node){
              if(color[v]==col) return false;
              
          }
          else if(v==node){
              if(color[u]==col) return false;
              
          }
              
          
      }
      return true;
      
  }
  bool solve(int node,int v, int m, vector<vector<int>> &edges,vector<int> &color){
      if(node==v) return true;
      for(int i=1;i<=m;i++){
          if(issafe(i,color,edges,node)){
              color[node]=i;
              if(solve(node+1,v,m,edges,color)) return true;
              color[node]=0;
          }
      }
      return false;
  }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> color(v,0);
        return solve(0,v,m,edges,color);
    }
};