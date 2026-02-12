class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = nums[0]
        i = 0 
        count = 0
        while i < len(nums):
            if count == 0:
                candidate = nums[i]
            if candidate == nums[i]:
                count += 1
                i += 1
            else:
                count -=1
                i += 1
        return candidate