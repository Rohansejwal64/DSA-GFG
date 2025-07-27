class Solution {
  public:
  void solve(vector<int>& arr, vector<int>& ans, int sum, int i) {
    if (i == arr.size()) {
        ans.push_back(sum);
        return;
    }
    // Include current element
    solve(arr, ans, sum + arr[i], i + 1);
    // Exclude current element
    solve(arr, ans, sum, i + 1);
}

vector<int> subsetSums(vector<int>& arr) {
    vector<int> ans;
    solve(arr, ans, 0, 0);
    return ans;
}

};