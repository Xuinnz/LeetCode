class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        lowest = 101
        highest = 0

        for i in range(len(nums)):
            if lowest > nums[i]:
                lowest = nums[i]
            if highest < nums[i]:
                highest = nums[i]
        arr = []
        for i in range(lowest, highest + 1):
            if i not in nums:
                arr.append(i)
        return sorted(arr)
