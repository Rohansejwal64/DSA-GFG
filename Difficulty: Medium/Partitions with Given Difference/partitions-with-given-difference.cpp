class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum<d) return 0;
        if((d+sum) %2 !=0) return 0;
        int k=(d+sum)/2;
         int n=arr.size();
        vector<int> dp(k+1,0);
        if(k>=arr[0]) dp[arr[0]]=1;
        if(arr[0]==0){
            dp[0]=2;
        }
        else{
            dp[0]=1;
        }
        for(int i=1;i<=n-1;i++){
            vector<int> curr(k+1,0);
            for(int j=0;j<=k;j++){
                int np=dp[j];
        int p=0;
        if(arr[i]<=j){
            p=  dp[j-arr[i]]; 
        }
         curr[j]=np+p;
                
            }
            dp=curr;
        }
        
        return dp[k];
    }
};