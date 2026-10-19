class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        arr = sorted(nums)
        ans = []
        for i in range(len(arr)):
            if arr[i] == target:
                ans.append(i)
        return ans
