import string
class Solution:
    def distinctSubseqII(self, s: str) -> int:
        distLt = {}
        for i, j in enumerate(string.ascii_lowercase, start=1):
            distLt[j] = 0
        for c in s:
            distLt[c] = 1 + sum(distLt.values())
        return sum(distLt.values()) % (10 ** 9 + 7)

