// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        
         int n = price.size();
         int t=n;
    vector<int> dp(t+1, 0);

    // base case: only item 0
    for (int i = 0; i <= t; i++) {
        dp[i] = i * price[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= t; j++) {   // ✅ forward loop for unbounded
            int np = dp[j];   // not pick
            int p = 0;
            if (i+1 <= j) {
                p = price[i] + dp[j - i-1];  // can reuse item i
            }
            dp[j] = max(np, p);
        }
    }

    return dp[t];
    }
};