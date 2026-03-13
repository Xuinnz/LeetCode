class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        bits = [0] * n
        def increment(bits):
            for i in range(n - 1, -1, -1):
                if bits[i] == 0:
                    bits[i] = 1
                    return bits
                else: 
                    bits[i] = 0
            return bits
        for _ in range(2 ** n):
            path = []
            for j in range(n):
                if bits[j] == 1:
                    path.append(nums[j])
            res.append(list(path))
            increment(bits)
        return res
