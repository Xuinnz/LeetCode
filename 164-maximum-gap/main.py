class Solution:
    def maximumGap(self, nums: list[int]) -> int:
        sortArr = sorted(nums)
        gap = 0
        for i in range(len(nums) - 1):
           gap = max(gap, sortArr[i + 1] - sortArr[i])
        return gap 
