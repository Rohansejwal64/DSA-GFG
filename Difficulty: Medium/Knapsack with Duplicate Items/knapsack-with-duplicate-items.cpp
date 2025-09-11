// User function Template for C++

class Solution {
  public:
  int solve(vector<int>& val, vector<int>& wt, int t,vector<vector<int>> &dp,int i){
      if(t==0) return 0;
      if(i==0){
          if(wt[i]<=t){
              return (t/wt[i])*val[i];
          }
          else{
              return 0;
          }
      }
      if(dp[i][t]!=-1) return dp[i][t];
      int np=solve(val,wt,t,dp,i-1);
      int p = 0;
      if(wt[i]<=t){
          p=val[i]+solve(val,wt,t-wt[i],dp,i);
      }
      
      return dp[i][t]=max(np,p);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int t) {
        int n= val.size();
        vector<vector<int>> dp(n,vector<int>(t+1,-1));
        return solve(val,wt,t,dp,n-1);
        
    }
};