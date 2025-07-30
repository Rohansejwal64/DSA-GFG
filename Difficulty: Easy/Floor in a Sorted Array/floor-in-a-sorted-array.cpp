class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int ans=-1;
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(arr[mid]>x){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};
