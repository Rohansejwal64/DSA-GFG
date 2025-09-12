class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        int ans=0;
        vector<int> dp(m+1,0);
        for(int i=1;i<=n;i++){
           
            for(int j=m;j>=1;j--){
                if(s1[i-1]==s2[j-1]){
                    dp[j]=dp[j-1]+1;
                    ans=max(ans,dp[j]);
                }
                else{
                    dp[j]=0;
                }
            }
            
        }
        return ans;
    }
};
