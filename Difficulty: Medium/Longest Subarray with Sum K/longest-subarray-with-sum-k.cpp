class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
         int n=arr.size();
        int largest=0;
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                largest=max(largest,i+1);
            }
            int rem=sum-k;
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