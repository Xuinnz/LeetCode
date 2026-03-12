class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        num = list(range(1, n + 1))
        res = []
        def backtrack(start, path, curr): #start - num ; path - arr; curr - currentPath number
            if curr == k:
                res.append(list(path))
                return
            for i in range(start, n + 1):
                path.append(i)
                backtrack(i + 1, path, curr + 1)
                path.pop()
        backtrack(1, [], 0)

        return res
