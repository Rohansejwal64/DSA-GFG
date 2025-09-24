class Solution {
  public:
    string reverse(const string& S) {
        // code here
        int n=S.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            char temp=S[i];
            st.push(temp);
        }
        
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
        }
};