class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        numsSum = sum(nums)
        target = numsSum - x
        ans = -1
        i, j = 0, 0
        length = len(nums)
        if target == 0:
            return length
        # [1, 1, 3, 2, 5]
        #  i     j
        # target = 7
        temp = nums[0]
        while i <= j and j < length:
            if temp < target:
                j += 1
                if j < length: temp += nums[j]
            elif temp > target:
                temp -= nums[i]
                i += 1
                if i - 1 == j:
                    j += 1
                    if j < length: temp += nums[j]
            else:
                if ans == -1:
                    ans = length - ((j - i) + 1)
                else:
                    ans = min(ans, length - ((j - i) + 1))
                if j < length:
                    j += 1
                    if j < length: temp += nums[j]
                else:
                    break
        return ans


        
