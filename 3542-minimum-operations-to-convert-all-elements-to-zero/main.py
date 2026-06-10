class Solution:
    def minOperations(self, nums: List[int]) -> int:
        cleaned = []
        for num in nums:
            if not cleaned or num != cleaned[-1]:
                cleaned.append(num)
        res = 0
        alive = []
        for i in cleaned:
            if (not alive or alive[-1] < i) and i != 0:
                alive.append(i)
            else:
                while alive and alive[-1] > i:
                    alive.pop()
                    res += 1
                if (not alive or (alive and alive[-1] != i)) and i != 0:
                    alive.append(i)
        while alive:
            alive.pop()
            res += 1
        return res
