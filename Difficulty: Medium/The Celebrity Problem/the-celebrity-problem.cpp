class Solution {
  public:
  bool cc(int c,vector<vector<int>>& mat){
      for(int i=0;i<mat.size();i++ ){
          
              if(mat[i][c]==0) return false;
          
      }
      return true;
      
  }
  bool cr(int r,vector<vector<int>>& mat ){
      for(int i=0;i<mat.size();i++ ){
          if(i!=r){
              if(mat[r][i]==1) return false;
          }
      }
      return true;
  }
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            if(cr(i,mat) && cc(i,mat)){
                ans=i;
                break;
                
            }
        }
        return ans;
    }
};