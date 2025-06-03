class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        d=d%arr.size();
        vector<int> temp(arr.size());
        for(int i=0;i<arr.size();i++){
            temp[(i+arr.size()-d)%arr.size()]=arr[i];
        }
        arr=temp;
    }
};