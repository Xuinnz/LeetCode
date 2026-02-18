class Solution:
    def rob(self, nums: List[int]) -> int:
        arr = []
        for i, n in enumerate(nums):
            if i == 0:
                arr.append(n)
            elif i == 1:
                arr.append(max(arr[i - 1], n))
            else:
                arr.append(max(arr[i - 2] + n, arr[i - 1]))
        return arr.pop()
