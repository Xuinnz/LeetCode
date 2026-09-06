class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        rows = len(t)
        cols = len(s)
        dp = [[0] * (cols + 1) for _ in range(rows + 1)]
        
        for i in range(cols + 1):
            dp[0][i] = 1

        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                if t[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        return dp[rows][cols]

