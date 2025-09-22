class Solution {
  public:
  priority_queue<int> maxipq;
  priority_queue<int , vector<int>, greater<int> > minipq;
  
  void arrange(){
      int l=maxipq.size();
      int r=minipq.size();
      if(l==r || l-r==1) return;
      if(r>l){
          maxipq.push(minipq.top());
          minipq.pop();
      }
      else{
          minipq.push(maxipq.top());
          maxipq.pop();
          
      }
      return;
      
  }
    vector<double> getMedian(vector<int> &arr) {
        // code here
        
        vector<double> ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            if(maxipq.empty()) maxipq.push(arr[i]);
            else{
                if(maxipq.top()<=arr[i]) minipq.push(arr[i]);
                else{
                    maxipq.push(arr[i]);
                }
            }
            arrange();
            int n=maxipq.size()+minipq.size();
            if(n%2==0){
                double median= maxipq.top()+minipq.top();
                median /=2;
                ans[i]=median;
                
            }
            else{
                ans[i]=maxipq.top();
                
                
            }
            
        }
        return ans;
    }
};
