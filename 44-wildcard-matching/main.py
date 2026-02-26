class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        ptrS, ptrP = 0, 0
        ptrStar = -1
        ptrTempS = -1
        while ptrS < len(s):
            if ptrP < len(p) and (p[ptrP] == s[ptrS] or p[ptrP] == '?'):
                ptrP += 1
                ptrS += 1
            elif ptrP < len(p) and p[ptrP] == '*':
                ptrStar = ptrP
                ptrTempS = ptrS
                ptrP += 1
            elif ptrStar != -1:
                ptrTempS += 1
                ptrS = ptrTempS
                ptrP = ptrStar + 1
            else:
                return False
        return all(x == '*' for x in p[ptrP:])
            
