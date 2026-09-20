import string
class Solution:
    def reverseDegree(self, s: str) -> int:
        hashmap = {}
        for index, value in enumerate(string.ascii_lowercase, start = 1):
            hashmap[value] = 27 - index
        ans = 0
        for i, c in enumerate(s, start = 1):
            ans += (hashmap[c] * i)
        return ans
