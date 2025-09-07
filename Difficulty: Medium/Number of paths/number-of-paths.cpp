class Solution {
  public:
  int solve(int i, int j, vector<vector<int>> &dp){
      int m=dp.size();
      int n=dp[0].size();
      if(i>=m || j>=n) return 0;
      if(i==m-1 && j==n-1) return 1;
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      int r=solve(i,j+1,dp);
      int d=solve(i+1,j,dp);
      return dp[i][j]=r+d;
  }
    int numberOfPaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,dp);
        
    }
};
