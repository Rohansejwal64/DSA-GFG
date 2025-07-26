// User function Template for C++

class Solution {
  public:
  void solve(int &n,string temp,vector<string> &ans){
      if(temp.size()==n){
          ans.push_back(temp);
          return;
      }
      solve(n,temp+'0',ans);
      if(temp.empty() || temp[temp.size()-1]=='0'){
          solve(n,temp+'1',ans);
      }
  }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        solve(num,"",ans);
        return ans;
    }
};