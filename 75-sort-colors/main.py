class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        end = n - 1
        start = 0
        startOne = 0
        i = 0
        while start <= end:
            if nums[i] == 2:
                nums[end], nums[i] = nums[i], nums[end]
                end -= 1
            elif nums[i] == 1:
                start += 1
                i += 1
            else:
                nums[startOne], nums[i] = nums[i], nums[startOne]
                startOne += 1
                start += 1
                i += 1
    # 2 0 1
    # 1 0 2

            


        