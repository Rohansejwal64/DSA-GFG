// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
         vector<int> ans(1,1);
         while(n){
             int c=0;
             int size=ans.size();
             for(int i=0;i<size;i++){
                 int res=ans[i]*n + c;
                 ans[i]=res%10;
                 c=res/10;
             }
             while(c){
                 int temp=c%10;
                 ans.push_back(temp);
                 c=c/10;
             }
             
             
             
             
             n--;
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};