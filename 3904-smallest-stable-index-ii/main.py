class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        prefMax = []
        sufMin = []
        for num in nums:
            if not prefMax:
                prefMax.append(num)
                continue
            prefMax.append(max(prefMax[-1], num))

        for num in nums[::-1]:
            if not sufMin:
                sufMin.append(num)
                continue
            sufMin.append(min(sufMin[-1], num))
        sufMin.reverse()

        for i in range(len(nums)):
            score = prefMax[i] - sufMin[i]
            if score <= k:
                return i
        return -1
