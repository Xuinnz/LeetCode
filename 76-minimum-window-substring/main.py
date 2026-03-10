from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        count = Counter(t)
        curr = Counter()
        j = 0
        res = []
        i = 0
        minCount = float('inf')
        while i < len(s): # j, i
            if s[i] not in count: #if not in t
                i += 1
                continue
            curr[s[i]] += 1   
            i += 1
            while curr >= count: #check if string are match
                current_len = i - j
                if current_len < minCount:
                    minCount = current_len
                    res = [j, i]
                if s[j] in count:
                    curr[s[j]] -= 1
                j += 1
                while j < i and s[j] not in count:
                    j += 1
        if not res:
            return ""
        return s[res[0]: res[1]]