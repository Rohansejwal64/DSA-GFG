class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n=s.size();
        vector<int> ans(n,0);
        int px=0;
        int sx=1;
        while(sx<n){
            if(s[px]==s[sx]){
                ans[sx]=px+1;
                sx++;
                px++;
                
            }
            else{
                if(px==0){
                    ans[sx]=0;
                    sx++;
                }
                else{
                    px=ans[px-1];
                    
                }
            }
        }
        return ans[n-1];
    }
};