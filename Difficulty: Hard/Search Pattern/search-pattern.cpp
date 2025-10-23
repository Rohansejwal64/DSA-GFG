class Solution {
  public:
  
  void getLPSLength(string &s,vector<int> &ans) {
        // code here
        int n=s.size();
       
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
        
    }
    vector<int> search(string &needle, string &haystack) {
        // code here
         int n=haystack.size();
        int m=needle.size();
        if(m>n) return {};
        vector<int> ans(m,0);
        getLPSLength(needle,ans);
        vector<int> res;
        
        
        int f=0;
        int s=0;
        while(f<n ){
            if(s>=m){
                res.push_back(f-s);
                int idx=ans[s-1];
                    s=idx;
            }
            if(haystack[f]==needle[s]){
                f++;
                s++;
            }
            else{
                if(s==0){
                    f++;
                }
                else{
                    int idx=ans[s-1];
                    s=idx;
                }
            }
        }
        if(s>=m){
            res.push_back(f-s);
        }
       
       return res;
        
    }
};