class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        count = {}
        maxCount = max(nums)
        for i in range(len(nums)):
            if nums[i] not in count:
                count[nums[i]] = 1
        
        for i in range(k, maxCount + 1, k):
            if i not in count:
                return i
        index = maxCount // k
        return k * (index + 1)
