class Solution:
    def isPalindrome(self, s: str) -> bool:
        string1 = ""
        for i, n in enumerate(s):
            if n.isalpha() or n.isnumeric():
                string1 += n
            else:
                continue
        string1 = string1.lower()
        string2 = string1[::-1]
        if string1 == string2:
            return True
        return False
