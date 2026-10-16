class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        j = k % n
        new = []
        for i in range(n - j, len(nums)):
            new.append(nums[i])
        for i in range(0, n - j):
            new.append(nums[i])
        nums[:] = new

            
        
