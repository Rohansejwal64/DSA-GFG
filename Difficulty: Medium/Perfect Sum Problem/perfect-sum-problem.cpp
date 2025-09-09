class Solution {
  public:
    int solve(vector<int>& arr,int k , int i,vector<vector<int>> &dp){
        
        if(i==0){
            if(k==0 && arr[i]==0) return 2;
            if(k==0 && arr[i]!=0) return 1;
            if(arr[i]==k) return 1;
            else{
                return 0;
            }
         }
        if(dp[i][k]!=-1) return dp[i][k];
        
        int np=solve(arr,k,i-1,dp);
        int p=0;
        if(arr[i]<=k){
            p=solve(arr,k-arr[i],i-1,dp);
        }
        return dp[i][k]=np+p;
    }
    int perfectSum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(arr,k,n-1,dp);
    }
};