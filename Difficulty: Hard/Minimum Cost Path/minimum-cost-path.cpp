

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
  int minimumCostPath(vector<vector<int>>& grid) {
    int n = grid.size();
    
    // DP table to store the minimum cost to reach cell (i, j).
    // Initialize with a large value.
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    // Priority queue to decide the order of DP state computation.
    // It stores {cost, {row, col}}. We prioritize the state with the smallest cost.
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize the starting state.
    dp[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});
    
    // Directions to move: up, down, left, right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    while (!pq.empty()) {
        // Get the state with the smallest cost to process next.
        int cost = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        
        // If we found a better path to this cell already, skip.
        if (cost > dp[r][c]) {
            continue;
        }
        
        // Use the current state's value to update its neighbors.
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Check for valid neighbors.
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                // The "relaxation" step: can we find a cheaper path to the neighbor?
                if (dp[r][c] + grid[nr][nc] < dp[nr][nc]) {
                    // Update the DP table with the new minimum cost.
                    dp[nr][nc] = dp[r][c] + grid[nr][nc];
                    // Add the updated state to the queue to be processed.
                    pq.push({dp[nr][nc], {nr, nc}});
                }
            }
        }
    }
    
    // The final answer is the minimum cost to reach the bottom-right cell.
    return dp[n - 1][n - 1];
}

};