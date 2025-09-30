class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if((s[i]>='a' && s[i] <='z')  || (s[i]>='A' && s[i] <='Z') ){
                continue;
            }
            else{
                if(s[i] == '('  || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                    st.push(s[i]);
                }
                else{
                    if(st.top() == '(') return true;
                    else{
                        while(st.top() != '(') st.pop();
                        st.pop();
                    }
                }
            }
        }
        return false;
        
    }
};
