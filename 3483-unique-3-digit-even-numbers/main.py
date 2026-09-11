from collections import Counter
class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        """
        since this is a 3 digit even numbers, i only need to check 100-999 numbers i guess?
        what if i for loop from 100 - 999 and check if i can build it?
        """
        counts = Counter(str(d) for d in digits)
        ans = 0
        for i in range(100, 1000, 2):
            count = Counter(str(i))
            if count <= counts:
                ans += 1
        return ans
                
