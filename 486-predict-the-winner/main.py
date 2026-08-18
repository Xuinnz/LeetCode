class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[0] * n for _ in range(n)]

        for interval in range(1, n + 1):
            i = 0
            for j in range(interval - 1,n):
                if i == j:
                    dp[i][j] = nums[i]
                else:
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
                i += 1
        return True if dp[0][n - 1] >= 0 else False
                
        
