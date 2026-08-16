class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        hashmap = {}
        hashmap[0] = 0
        hashmap[1] = 0
        hashmap[2] = 0
        for i in range(len(stones)):
            hashmap[stones[i] % 3] += 1

        if hashmap[0] % 2 == 0:
            if hashmap[1] >= 1 and hashmap[2] >= 1:
                return True
            return False
        else:
            if abs(hashmap[1] - hashmap[2]) > 2:
                return True
            return False
