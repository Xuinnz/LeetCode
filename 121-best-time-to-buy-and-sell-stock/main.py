class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0
        i = 0
        n = len(prices) - 1
        lowest = prices[i]
        highest = 0
        while i <= n:
            if prices[i] < lowest and i != n: 
                lowest = prices[i]
                highest = 0
            elif prices[i] > highest: 
                highest = prices[i]
                profit = highest - lowest
                if maxProfit < profit: maxProfit = profit
            i += 1
        return maxProfit if maxProfit > 0 else 0
