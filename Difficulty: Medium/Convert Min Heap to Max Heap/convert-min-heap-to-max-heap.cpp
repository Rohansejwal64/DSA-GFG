// User function Template for C++

class Solution {
  public:
  
  void heapify(vector<int> &arr,int n, int i){
      int largest=i;
      int lc=2*i+1;
      int rc=2*i+2;
      if(lc<n && arr[lc]>arr[largest]) largest=lc;
      if(rc<n && arr[rc]>arr[largest]) largest=rc;
      if(largest!=i){
          swap(arr[i],arr[largest]);
          heapify(arr,n,largest);
      }
      
  }
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        
        
       
        int n=arr.size();
        for(int i=(n/2)-1 ; i>=0;i--){
            heapify(arr,n,i);
        }
    }
};
