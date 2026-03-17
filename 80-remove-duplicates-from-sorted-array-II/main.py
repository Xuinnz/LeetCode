class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        j = len(nums) - 2
        while i < j:
            if nums[i] == nums[i + 1] and nums[i + 1] == nums[i + 2]:
                nums.pop(i)
                j -= 1
                continue
            i += 1
