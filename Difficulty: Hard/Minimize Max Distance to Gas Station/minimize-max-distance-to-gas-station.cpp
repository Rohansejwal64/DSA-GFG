class Solution {
  public:
   double minMaxDist(vector<int> &stations, int K) {
    int n = stations.size();
    double left = 0, right = stations[n - 1] - stations[0];
    double result = right;
    
    // Binary search for the minimum possible maximum distance
    while (right - left > 1e-6) {
        double mid = (left + right) / 2.0;
        int stationsNeeded = 0;
        
        // Calculate how many additional stations are needed to achieve max distance <= mid
        for (int i = 0; i < n - 1; i++) {
            double segmentLength = stations[i + 1] - stations[i];
            stationsNeeded += ceil(segmentLength / mid) - 1;
        }
        
        if (stationsNeeded <= K) {
            // We can achieve this maximum distance with K or fewer stations
            result = mid;
            right = mid;
        } else {
            // We need more than K stations to achieve this maximum distance
            left = mid;
        }
    }
    
    return result;
}
};