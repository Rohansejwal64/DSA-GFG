class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> bck(n,0);
        int li=0;
        int maxi=0;
        for(int i=0;i<=n-1;i++){
            bck[i]=i;
            for(int j=0;j<=i-1;j++){
                if(arr[i]>arr[j]){
                    
                    if(dp[i]<dp[j]+1){
                        dp[i]=max(dp[i],dp[j]+1);
                        bck[i]=j;
                    }
                    
                }
            }
            
            if(maxi<dp[i]){
                maxi=max(maxi,dp[i]);
                li=i;
            }
            
        }
        
        vector<int> ans;
        ans.push_back(arr[li]);
        while(bck[li]!=li){
            ans.push_back(arr[bck[li]]);
            li=bck[li];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};