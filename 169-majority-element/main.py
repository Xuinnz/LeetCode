class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = {}
        for i, n in enumerate(nums):
            if nums[i] in count:
                count[n] += 1
            else: 
                count[n] = 1
            if count[n] > len(nums) // 2:
                return n