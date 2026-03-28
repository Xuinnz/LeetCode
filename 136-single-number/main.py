class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_set = {}

        for key, val in enumerate(nums):
            if val not in hash_set:
                hash_set[val] = 1
            elif val in hash_set:
                hash_set[val] += 1
        
        for i in hash_set:
            if hash_set[i] == 1:
                return i
        return 0
        
