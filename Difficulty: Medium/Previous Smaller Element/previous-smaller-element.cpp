class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            while( st.top() !=-1 && st.top()>=arr[i]) st.pop();

            ans[i]=st.top();
            st.push(arr[i]);

        }
        return ans;
        
    }
};