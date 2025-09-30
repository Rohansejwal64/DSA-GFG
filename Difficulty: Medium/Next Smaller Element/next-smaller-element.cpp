class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
       vector<int> ans(n);
       stack<int> st;
       st.push(-1);
       for(int i=n-1;i>=0;i--){
           while(st.top() >=arr[i]){
                   st.pop();
               }
                ans[i]=st.top();
               st.push(arr[i]);
           
           
       }
       return ans;
    }
};