class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low>=high){
            return;
        }
        int loc=partition(arr,low,high);
        quickSort(arr,low,loc-1);
        quickSort(arr,loc+1,high);
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pivot=arr[low];
        int st=low;
        int end=high;
        while(st<end){
            while(arr[st]<=pivot) st++;
            while(arr[end]>pivot) end--;
            if(st<end){
                swap(arr[st],arr[end]);
            }
        }
        swap(arr[end],arr[low]);
        return end;
    }
};