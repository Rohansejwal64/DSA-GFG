class Solution {
  public:
  bool possible(vector<int> &arr, int k,int mid){
      int i=1;
      int count=1;
      int prep=arr[0];
      while(i<arr.size()){
          int curp=arr[i];
          if(curp-prep>=mid){
              count++;
              prep=curp;
          }
          i++;
      }
      if(count>=k) return true;
      else{
          return false;
      }
  }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int maxi= *max_element(arr.begin(),arr.end());
        int mini=*min_element(arr.begin(),arr.end());
        int s=0;
        int e=maxi-mini;
        int ans;
        sort(arr.begin(),arr.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(arr,k,mid)){
                ans=mid;
                s=mid+1;
                
            }
            else{
                e=mid-1;
            }
            
        }
        return ans;
    }
};