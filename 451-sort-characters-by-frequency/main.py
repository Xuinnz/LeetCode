from collections import Counter
from operator import itemgetter
class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)
        sorted_map = dict(sorted(c.items(), key=itemgetter(1), reverse = True))
        outputStr = ""
        for i, n in sorted_map.items():
            while n > 0:
                outputStr += i
                n -= 1 
        outputStr = "".join(i * n for i, n in sorted_map.items())
        return outputStr

