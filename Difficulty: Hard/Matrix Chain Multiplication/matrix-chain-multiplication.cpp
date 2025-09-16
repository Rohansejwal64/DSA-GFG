class Solution {
  public:
  
    int solve(vector<int> &arr,vector<vector<int>> &dp,int i, int j){
        if(i==j) return 0;

         if(dp[i][j]!=-1) return dp[i][j];
         int mini=INT_MAX;
         for(int k=i ;k<=j-1 ;k++){
             int steps= solve(arr,dp,i,k) + solve(arr,dp,k+1,j)+ arr[i-1]* arr[k] * arr[j];
             mini=min(mini,steps);
         }
         return dp[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,dp,1,n-1);
    }
};