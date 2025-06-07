/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n=arr.size();
        int largest=0;
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                largest=max(largest,i+1);
            }
            int rem=sum-0;
            if(mp.find(rem)!=mp.end()){
                int len=i-mp[rem];
                largest=max(largest,len);
                
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
                
            }
            
        }
        return largest;
    }
};