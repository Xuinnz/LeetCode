class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        furthest = []
        for i in range(len(nums) - 1):
            if i == 0:
                curr = nums[0]
                if nums[0] >= len(nums):
                    curr = len(nums) - 1
                furthest.append(curr)
                continue
            curr = max(furthest[i - 1], i + nums[i])
            if curr >= len(nums):
                curr = len(nums) - 1
            furthest.append(curr)
        jump_counter = 0
        i = 0
        while i != furthest[-1]:
            i = furthest[i]
            jump_counter += 1
        return jump_counter

