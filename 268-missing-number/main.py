class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        length = len(nums) - 1
        i = 0
        while i <= length:
            n = nums[i]
            if i == n or n < 0 or n > length:
                i += 1
            else:
                nums[i], nums[n] = nums[n], nums[i]
# 0 1 2 3 4 5
# 0 1 2 3 4 5
        
        for i, n in enumerate(nums):
            if i != n:
                return i
        return nums[length] + 1