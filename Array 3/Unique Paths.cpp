class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(m-1, n-1, memo);
    }

private:
    int dp(int m, int n, vector<vector<int>> &memo) {
        if (m < 0 || n < 0) return 0;
        if (m == 0 && n == 0) return 1;
        if (memo[m][n] != -1) return memo[m][n];

        memo[m][n] = dp(m-1, n, memo) + dp(m, n-1, memo);
        return memo[m][n];
    }
};
