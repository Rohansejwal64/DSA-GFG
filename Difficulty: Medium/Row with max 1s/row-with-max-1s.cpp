// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int r=arr.size();
        int c=arr[0].size();
        int i=0;
        int j=0;
        int index=-1;
        int maxi=0;
        while(i>=0 && i<r && j>=0 && j<c){
            if(arr[i][j]==0) {
                j++;
                if(j>=c){
                    j=0;
                    i++;
                }
                
            }
            else{
                if(maxi<c-j){
                    maxi=c-j;
                    index=i;
                }
                j=0;
                i++;
                
                
            }
        }
        return index;
    }
};