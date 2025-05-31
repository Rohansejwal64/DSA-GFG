class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& nums) {
        // Your code here
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int flag=0;
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    flag=1;
                }

            }
            if(flag==0){
                break;
            }
        }
        
    }
};