class Solution {
  public:
    bool solve(vector<int>& arr, int k,vector<vector<int>> &dp,int i){
        if(k==0) return true;
        if(i==0){
            if(arr[0]==k) return true;
            else{
                return false;
            }
        }
        if(dp[i][k] !=-1) return dp[i][k];
        
        bool nt=solve(arr,k,dp,i-1);
        if(nt==true) return nt;
        bool t=false;
        if(k>=arr[i]){
            t=solve(arr,k-arr[i],dp,i-1);
        }
        return dp[i][k]=(nt || t);
    }
    bool isSubsetSum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(arr,k,dp,n-1);
    }
};