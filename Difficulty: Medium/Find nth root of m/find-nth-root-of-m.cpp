class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int ans=-1;
        for(int i=0;i<=m;i++){
            long long temp=1;
            for(int j=0;j<n;j++){
                temp*=i;
            }
            
            if(temp==m) ans=i;;
            
            if(temp>m) break;
        }
        return ans;
    }
};