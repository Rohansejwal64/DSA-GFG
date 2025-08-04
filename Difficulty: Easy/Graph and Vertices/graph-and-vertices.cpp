// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // your code here
        long long x=n*(n-1)/2;
        long long ans;
        ans=pow(2,x);
        return ans;
    }
};