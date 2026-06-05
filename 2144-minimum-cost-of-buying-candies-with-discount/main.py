class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort()
        cost.reverse()
        price = 0
        for i,n in enumerate(cost):
            if (i + 1) % 3 == 0:
                continue
            price += n
        return price
        
