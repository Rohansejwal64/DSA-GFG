class Solution {
  public:
    int findSubString(string& s) {
        // code here
        vector<bool> uniq(26,false);
        int un=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(uniq[ch-'a'] ==false){
                uniq[ch-'a'] =true;
                un++;
                
            }
        }
        int ans=s.size();
        unordered_map<char,int> mp;
        int l=0;
        int r=0;
        while(r<s.size()){
            mp[s[r]]++;
            if(mp.size()==un){
                while(mp[s[l]] >1){
                    mp[s[l]]--;
                    l++;
                }
                ans=min(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};