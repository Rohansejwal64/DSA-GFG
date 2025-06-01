class Solution {
  public:
  void merge(vector<int> &arr,int l,int mid,int r){
      vector<int> left(mid-l+1);
      vector<int> right(r-mid);
      for(int i=0;i<=mid-l;i++){
          left[i]=arr[l+i];
      }
      for(int i=0;i<=r-mid-1;i++){
          right[i]=arr[mid+1+i];
      }
      
      int i=0;
      int j=0;
      int k=l;
      while(i<=mid-l && j<=r-mid-1){
          if(left[i]<=right[j]){
              arr[k]=left[i];
              i++,k++;
          }
          else{
              arr[k]=right[j];
              j++,k++;
          }
      }
      while(i<=mid-l){
          arr[k]=left[i];
          k++,i++;
      }
      while(j<=r-mid-1){
          arr[k]=right[j];
          k++,j++;
      }
      
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};