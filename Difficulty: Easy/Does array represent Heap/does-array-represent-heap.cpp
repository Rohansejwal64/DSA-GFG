
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        int i=n-1;
        while(i>0){
            int p=(i-1)/2;
            if(arr[p]<arr[i]) return 0;
            i--;
            
        }
        return 1;
    }
};