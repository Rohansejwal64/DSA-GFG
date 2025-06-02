class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int lar=arr[0];
        int seclar=-1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>lar){
                seclar=lar;
                lar=arr[i];
            }
         if(arr[i]<lar && arr[i]>seclar){
             seclar=arr[i];
         }
            
        }
        return seclar;
    }
};