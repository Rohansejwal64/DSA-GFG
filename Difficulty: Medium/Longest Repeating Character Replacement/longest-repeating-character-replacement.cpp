class Solution {
  public:
    int characterReplacement(string& s, int k) {
        // code here
        int n=s.size();
        int l=0,r=0,maxlen=0,maxf=0;
        int hash[26]={0};
        while(r<n){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            int changes=(r-l+1)-maxf;
            if(changes>k){
                hash[s[l]-'A']--;
                l++;
            }
            changes=(r-l+1)-maxf;
            if(changes<=k) maxlen=max(maxlen,r-l+1);
            r++;
            
        }
        return maxlen;
    }
};