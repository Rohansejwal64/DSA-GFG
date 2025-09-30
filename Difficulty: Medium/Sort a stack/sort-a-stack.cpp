class Solution {
  public:
  void corrpos(stack<int> &st, int x){
      if(st.empty()){
          st.push(x);
          return;
      }
      
      int temp=st.top();
      if(x>= temp){
          st.push(x);
          return;
      }
      else{
          st.pop();
          corrpos(st,x);
          st.push(temp);
      }
  }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int temp=st.top();
        st.pop();
        sortStack(st);
        corrpos(st,temp);
    }
};
