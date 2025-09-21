// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int n) {
        
        vector<int> temp(n);
        temp=arr;
        sort(temp.begin(),temp.end());
         vector<int> ans(n);
         unordered_map<int,int> mp;
         
         int i=0;
         int r=1;
         while(i<n){
             int ele=temp[i];
             
             if(mp.find(ele)==mp.end()) {
                 mp[ele]=r;
                 r++;
             }
             i++;
         }
         
         
         for(int j=0;j<n;j++){
             ans[j]=mp[arr[j]];
         }
         return ans;
    }
};
