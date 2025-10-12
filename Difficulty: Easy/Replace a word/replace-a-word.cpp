// User function Template for C++
class Solution {
  public:
    string replaceAll(string S, string oldW, string newW) {
    // It's good practice to handle the case where oldW is empty.
    if (oldW.empty()) {
        return S;
    }

    string result = "";
    int i = 0;
    while (i < S.length()) {
        // Check if a substring of S starting at i matches oldW.
        // The first part of the condition prevents going out of bounds.
        if (i <= S.length() - oldW.length() && S.substr(i, oldW.length()) == oldW) {
            // Match found! Append the new word.
            result += newW;
            // Jump the index past the word we just replaced.
            i += oldW.length();
        } else {
            // No match, so just append the current character.
            result += S[i];
            // Move to the next character.
            i++;
        }
    }
    return result;
}
};