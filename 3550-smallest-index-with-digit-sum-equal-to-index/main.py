class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i, n in enumerate(nums):
            temp = 0
            while n > 0:
                temp += (n % 10)
                n = n // 10
            if temp == i:
                return i
        return -1
