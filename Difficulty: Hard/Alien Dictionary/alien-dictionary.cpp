class Solution {
  public:
    

string findOrder(vector<string> &words) {
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    vector<bool> present(26, false);

    int n = words.size();

    // Mark all present characters
    for (string &w : words) {
        for (char c : w) present[c - 'a'] = true;
    }

    // Build graph from word list
    for (int i = 0; i < n - 1; i++) {
        string &w1 = words[i];
        string &w2 = words[i + 1];
        int len = min(w1.size(), w2.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                indegree[w2[j] - 'a']++;
                found = true;
                break;
            }
        }

        // Invalid case: prefix order wrong (e.g., "abc" before "ab")
        if (!found && w1.size() > w2.size()) {
            return "";
        }
    }

    // BFS Kahn's Algorithm
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (present[i] && indegree[i] == 0) q.push(i);
    }

    string order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order += (char)(u + 'a');
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    // Count present letters
    int totalLetters = 0;
    for (bool p : present) if (p) totalLetters++;

    // If cycle → not all letters processed
    if (order.size() < totalLetters) return "";

    return order;
}

};