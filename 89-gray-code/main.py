class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans = [0, 1]
        if n == 1:
            return ans
        for i in range(1, n):
            add = 2 ** i
            reverse = [x + add for x in ans[::-1]]
            ans += reverse
        return ans
