class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        maxlen = 0
        current = 0
        i = 0
        j = 0
        hashmap = {}
        while j < len(s):
            if s[j] not in hashmap or s[j] == 0:
                hashmap[s[j]] = 1
            else:
                hashmap[s[j]] += 1
                while hashmap[s[j]] > 2:
                    hashmap[s[i]] -= 1
                    i += 1
                    current -= 1
            current += 1    
            if current > maxlen:
                maxlen = current
            j += 1
        return maxlen
