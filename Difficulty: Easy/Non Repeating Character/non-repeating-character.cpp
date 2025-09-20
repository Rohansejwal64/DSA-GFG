
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        int n=s.size();
        unordered_map<char,int> mp;
        queue<char> q;
        for(int i=0;i<n;i++){
            if(mp[s[i]]==0){
                q.push(s[i]);
            }
            mp[s[i]]++;
            while(!q.empty() && mp[q.front()] >1){
                q.pop();
            }
            
        }
        q.push('$');
        return q.front();
        
    }
};