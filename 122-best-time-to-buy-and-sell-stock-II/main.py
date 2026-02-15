class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        arr = []
        i = 0
        n = len(prices) - 1
        while i < n:
            diff = prices[i + 1] - prices[i] 
            arr.append(diff)
            i += 1
        totalProfit = 0
        for key, val in enumerate(arr):
            if val > 0:
                totalProfit += val
        return totalProfit
