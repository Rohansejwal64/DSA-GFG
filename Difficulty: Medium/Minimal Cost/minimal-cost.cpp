class Solution {
  public:
  int solve(int k, vector<int>& arr,vector<int> &dp,int n){
      if(dp[n] !=-1) return dp[n];
      int i=1;
      int mini=INT_MAX;
      while(i<=k && i<=n){
          int temp=solve(k,arr,dp,n-i)+abs(arr[n]-arr[n-i]);
          mini=min(mini,temp);
          i++;
          
      }
      return dp[n]=mini;
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
       vector<int> dp(n);
        fill(dp.begin(), dp.end(), -1);
        dp[0]=0;
        return solve(k,arr,dp,n-1);
    }
};