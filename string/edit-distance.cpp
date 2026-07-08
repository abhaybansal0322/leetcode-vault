class Solution {
public:
    int n, m;
    vector<vector<int>> memo;

    int helper(int i, int j, string &word1, string &word2) {
        if (i == n) return m - j; // If word1 is exhausted, add remaining characters from word2
        if (j == m) return n - i; // If word2 is exhausted, remove remaining characters from word1

        if (memo[i][j] != -1) return memo[i][j];

        if (word1[i] == word2[j]) {
            return memo[i][j] = helper(i + 1, j + 1, word1, word2);
        }

        // Replace operation
        int replace = helper(i + 1, j + 1, word1, word2);

        // Insert operation
        int insert = helper(i, j + 1, word1, word2);

        // Delete operation
        int del = helper(i + 1, j, word1, word2);

        return memo[i][j] = 1 + min({replace, insert, del});
    }

    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, word1, word2);
    }
};
