from collections import Counter
class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if k == n:
            return max(nums)
        
        counts = Counter(nums)
        if k == 1:
            candidate = -1
            for key, val in counts.items():
                if val == 1 and key > candidate:
                    candidate = key
            return candidate
        if counts[nums[0]] > 1: #if [0] count is more than 1
            if counts[nums[-1]] > 1: #if [-1] count is more than 1 as well
               return -1
            return nums[-1] #if [0] count more than 1only
        elif counts[nums[-1]] > 1: # if [-1] count more than 1 only
            return nums[0]
        return nums[0] if nums[0] > nums[-1] else nums[-1]

