class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        hasZero = False
        total = 0

        for i, n in enumerate(nums):
            total = total ^ n
            if n != 0:
                hasZero = True
        if total != 0:
            return len(nums)
        elif hasZero == True:
            return len(nums) - 1
        else:
            return 0
