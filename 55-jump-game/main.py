class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if nums[0] == 0 and len(nums) > 1:
            return False
        elif nums[0] == 0 and len(nums) == 1:
            return True
        dp = 0
        for i in range(len(nums) - 1):
            if i == 0:
                dp = nums[i]
            elif nums[i] == 0 and dp <= i:
                    return False
            else:
                dp = max(dp, i + nums[i])
        return True
        

