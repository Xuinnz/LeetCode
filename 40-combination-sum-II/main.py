class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        def backtrack(remainder, stack, start_index):
            if remainder == 0:
                res.append(list(stack))
                return
            elif remainder < 0:
                return
            for i in range(start_index, len(candidates)):
                if i > start_index and candidates[i] == candidates[i - 1]:
                    continue
                stack.append(candidates[i])
                backtrack(remainder - candidates[i], stack, i + 1)
                stack.pop()

        backtrack(target, [], 0)
        return res
