from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        wordCount = len(words)
        charCount = (len(words[0])) * wordCount
        counts = Counter(words)
        i = 0
        arr = []
        while i + charCount <= len(s):
            substring = [s[j : j + len(words[0])] for j in range(i, i + charCount, len(words[0]))]
            counts2 = Counter(substring)
            if counts == counts2:
                arr.append(i)
            i += 1
        return arr
