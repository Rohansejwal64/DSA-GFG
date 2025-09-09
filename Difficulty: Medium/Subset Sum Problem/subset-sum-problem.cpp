class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int k) {
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    for(int i=0;i<=n-1;i++){ dp[i][0]=1; } 
    for(int i=1;i<=k;i++){
        if(arr[0]==i){ dp[0][i]=1;
        }
        else{
            dp[0][i]=0;
        }
        }
    for(int i=1;i<=n-1;i++){ for(int j=1;j<=k;j++){ bool nt=dp[i-1][j]; if(nt==true) dp[i][j]=1; bool t=false; if(j>=arr[i]){ t= dp[i-1][j-arr[i]]; } dp[i][j]=(nt || t); } } return dp[n-1][k];
}
};