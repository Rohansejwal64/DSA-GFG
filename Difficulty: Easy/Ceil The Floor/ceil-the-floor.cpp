// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int f=-1;
        int c=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=x){
                f=max(f,arr[i]);
            }
            if(arr[i]>=x){
                if(c==-1){
                    c=arr[i];
                }
                else{
                    c=min(c,arr[i]);
                }
            }
        }
        return {f,c};
    }
};