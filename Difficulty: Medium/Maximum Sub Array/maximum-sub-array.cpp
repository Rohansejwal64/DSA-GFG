// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
    int sum = 0;
    int st = 0;
    int ansst = -1, ansend = -1;
    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            sum = 0;
            continue;
        }
        if (sum == 0) st = i;
        sum += arr[i];

        if (sum > maxi || (sum == maxi && (i - st > ansend - ansst))) {
            maxi = sum;
            ansst = st;
            ansend = i;
        }
    }

    if (maxi == INT_MIN) {
        return {-1};
    }

    vector<int> ans;
    for (int i = ansst; i <= ansend; i++) {
        ans.push_back(arr[i]);
    }
    return ans;
}

};