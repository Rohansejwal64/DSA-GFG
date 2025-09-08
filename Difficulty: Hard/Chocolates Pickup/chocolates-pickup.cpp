class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp,int i, int j1, int j2){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return INT_MIN;
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=INT_MIN;
        
        for(int m1=-1;m1<=1;m1++){
            for(int m2=-1;m2<=1;m2++){
                int nj1=j1+m1;
                int nj2=j2+m2;
                if(j1==j2){
                    maxi=max(maxi,grid[i][j1]+solve(n,m,grid,dp,i+1,nj1,nj2));
                    
                }
                else{
                    maxi=max(maxi,grid[i][j2]+grid[i][j1]+solve(n,m,grid,dp,i+1,nj1,nj2));
                }
            }
        }
        return dp[i][j1][j2]=maxi;
        
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(n,m,grid,dp,0,0,m-1);
        
        
    }
};