
class Solution {
  public:

   vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    int n = arr.size();
    vector<int> nge_count(n, 0);
    
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[i]) cnt++;
        }
        nge_count[i] = cnt;
    }
    
    vector<int> result;
    for (int idx : indices) {
        result.push_back(nge_count[idx]);
    }
    return result;
}


};