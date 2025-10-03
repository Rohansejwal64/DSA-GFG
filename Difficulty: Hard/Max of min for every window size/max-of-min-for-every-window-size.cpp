class Solution {
  public:
   vector<int> maxOfMins(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n), res(n + 1, INT_MIN);
    stack<int> s;

    // Previous Smaller Element
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack for next step
    while (!s.empty()) s.pop();

    // Next Smaller Element
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Fill result array
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;  // window size where nums[i] is min
        res[len] = max(res[len], nums[i]);
    }

    // Fill the empty entries
    for (int i = n - 1; i >= 1; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    // Prepare final answer
    vector<int> ans(res.begin() + 1, res.end());
    return ans;
}

};