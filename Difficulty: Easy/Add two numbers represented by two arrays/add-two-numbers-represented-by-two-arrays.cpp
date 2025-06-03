

class Solution {
  public:
    string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        // Complete the function
        int m=arr1.size()-1;
        int n=arr2.size()-1;
        int carry=0;
        vector<int> ans;
        while(m>=0 && n>=0){
            int sum=arr1[m]+arr2[n]+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum);
            m--;
            n--;
            
        }
        while(m>=0){
            int sum=arr1[m]+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum);
            m--;
            
        }
        while(n>=0){
            int sum=arr2[n]+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back(sum);
            n--;
            
        }
        if(carry !=0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        string res;
        for(int i=0;i<ans.size();i++){
            res.push_back(ans[i]+'0');
        }
        return res;
        
    }
};