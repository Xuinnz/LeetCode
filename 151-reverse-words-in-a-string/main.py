class Solution:
    def reverseWords(self, s: str) -> str:
        i = 0
        n = len(s) - 1
        k = n
        revStr = ""
        while k >= 0:
            while k >= 0 and s[k] == " ":
                k -= 1
            if k < 0: break
            revStr += " " if revStr else ""
            currWord = ""
            while k >= 0 and s[k] != " ":
                currWord += s[k]
                k -= 1
            currWord = currWord[::-1]
            revStr += currWord

        return revStr

