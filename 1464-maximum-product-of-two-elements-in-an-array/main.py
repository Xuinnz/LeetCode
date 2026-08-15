class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        i = 0
        j = 0
        for key, val in enumerate(nums):
            if val >= i:
                j = i
                i = val
            elif val > j:
                j = val
        return (j - 1) * (i - 1)
        
