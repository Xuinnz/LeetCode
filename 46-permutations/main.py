class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [[nums[0]]]
        resArr = []
        def backtrack(nums, arr):
            diff = list(set(nums) - set(arr))
            if len(nums) == 1:
                resArr.append(list(arr))
                return
            for i, n in enumerate(diff):
                arr.append(n)
                backtrack(diff, arr)
                arr.pop()
        backtrack(nums, [])   
        return resArr  
        
