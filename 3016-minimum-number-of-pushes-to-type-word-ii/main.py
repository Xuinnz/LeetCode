from collections import Counter
class Solution:
    def minimumPushes(self, word: str) -> int:
        counts = sorted(Counter(word).values(), reverse=True)
        ans = 0
        # {a: 5, b: 4, c: 3, d: 2, e: 1}
        for i, val in enumerate(counts):
            ans += ((i // 8) + 1) * val
        return ans  
