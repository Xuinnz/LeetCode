class Solution:
    def maxDepth(self, s: str) -> int:
        cn = 0
        ans  = 0
        for c in s:
            if c == "(":
                cn += 1
                ans = max(ans, cn)
            elif c == ")":
                cn -= 1
        return ans 
