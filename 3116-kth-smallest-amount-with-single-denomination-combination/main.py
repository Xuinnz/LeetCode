import math
from itertools import combinations

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        # make the coins smaller
        sorted_coins = sorted(coins)
        filtered = []
        for c in sorted_coins:
            is_redundant = False
            for smaller in filtered:
                if c % smaller == 0:
                    is_redundant = True
            if not is_redundant:
                filtered.append(c)
        #
        n = len(filtered)
        subset = []
        for size in range(1, n + 1):
            sign = 1 if size % 2 == 1 else -1
            for combo in combinations(filtered,size):
                subset.append((math.lcm(*combo), sign))
        
        def count(mid):
            total = 0
            for sub in subset:
                if sub[1] == 1:
                    total += mid // sub[0]
                else:
                    total -= mid // sub[0]
            return total
        
        start = filtered[0]
        end = min(filtered) * k
        while end > start:
            mid = (start + end) // 2
            if count(mid) >= k:
                end = mid
            else:
                start = mid + 1
        return start

