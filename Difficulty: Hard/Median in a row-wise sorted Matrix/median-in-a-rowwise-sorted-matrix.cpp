class Solution {
  public:
  int upb(vector<int> &arr, int t) {
    int s = 0;
    int e = arr.size() - 1;
    int ans = arr.size(); // default: all elements <= t

    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] > t) {
            ans = mid;     // first index where element > t
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans; // count of elements <= t
}
  int solve(vector<vector<int>> &mat, int mid){
      int count=0;
      for(int i=0;i<mat.size();i++){
          count+=upb(mat[i],mid);
          
      }
      return count;
  }
    int median(vector<vector<int>> &mat) {
        // code here
        int r=mat.size();
        int c=mat[0].size();
        int s=1;
        int e=2000;
        int req=(r*c)/2;
        while(s<=e){
            int mid=(s+e)/2;
            int count=solve(mat,mid);
            if(count>req){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            
            
        }
        return s;
    }
};
