class Solution {
    int lcs(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if(i==word1.size() || j==word2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return 1 + lcs(word1, word2, i+1, j+1, dp);
        return dp[i][j] = max(lcs(word1, word2, i, j+1, dp), lcs(word1, word2, i+1, j, dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int a = lcs(word1, word2, 0, 0, dp);
        return n+m - 2*a;
    }
};