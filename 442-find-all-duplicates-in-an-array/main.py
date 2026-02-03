class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        hash_set = {}
        for i, n in enumerate(nums):
            if n in hash_set:
                hash_set[n] += 1
            elif n not in hash_set:
                hash_set[n] = 1
        arr = []
        for key, val in hash_set.items():
            if val > 1:
                arr.append(key)
        return arr
        