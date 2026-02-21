class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        def backtrack(remaining, stack, start_index):
            if remaining == 0:
                return res.append(list(stack))
            elif remaining < 0:
                return
            for i in range(start_index, len(candidates)):
                stack.append(candidates[i])
                backtrack(remaining - candidates[i], stack, i)
                stack.pop()
        backtrack(target, [], 0)
        return res

            
