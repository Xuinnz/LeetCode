import string
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        al = {}
        for i, j in enumerate(string.ascii_uppercase, start=1):
            al[j] = i
        
        rev_str = columnTitle[::-1]

        ans = 0
        for idx, val in enumerate(rev_str):
            value = al[val] * (26**idx)
            ans += value
        return ans

