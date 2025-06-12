// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
         int l=0,r=0,maxlen=-1;
        int n=s.size();
         map<char,int> mpp;
        while(r<n){
           
            
                mpp[s[r]]++;
            if(mpp.size() ==k){
                maxlen=max(maxlen,r-l+1);
            }
            if(mpp.size()>k){
                
                mpp[s[l]]--;
            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l++;
            }
            
            r++;
        }
        return maxlen;
    }
};