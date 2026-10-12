class Solution:
    def minInsertions(self, s: str) -> int:
        right = 0
        ans = 0
        for c in s:
            if c == "(":
                if right % 2 != 0:
                    ans += 1
                    right -= 1
                right += 2
            else:
                right -= 1
                if right < 0:
                    ans += 1
                    right += 2
        return ans + right
            #if count is 0, then it's balanced.
            #if count is -1 (or odd) and next is left, then we need
            # if -1, we need 2 (1 left + 1 right)
            # if -2, we need 1 (1 left)
            # if -3, we need 3 (2 left + 1 right)
            # if -4 we need 2 (2 left)
            # if -5, we need 4 (3 left  + 1 right)
            
