from functools import cache
class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        # my first thought is: backtracking everytime it hits a false
        # so if ) is higher than (, then we go back
        m = len(grid)   # vertical
        n = len(grid[0])# horizonatal
        if grid[0][0] == ")" or grid[m - 1][n - 1] == "(":
            return False
        if (m + n) % 2 == 0:
            return False
        @cache
        def dfs(count, trackM, trackN):
            if count < 0 or trackM >= m or trackN >= n:
                return False
            
            count += 1 if grid[trackM][trackN] == "(" else -1
        
            if trackM == (m - 1) and trackN == (n - 1) and count == 0:
                return True  

            return dfs(count, trackM + 1, trackN) or dfs(count, trackM, trackN + 1)
        
        return dfs(0, 0, 0)
                


