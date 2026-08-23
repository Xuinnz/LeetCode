class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        start = 0
        mid = n // 2
        qsCount = 0
        sumdiff = 0
        for i in range(mid):
            if num[i] == '?':
                qsCount += 1
            else:
                sumdiff += int(num[i])
        
        for i in range(mid, n):
            if num[i] == '?':
                qsCount -= 1
            else:
                sumdiff -= int(num[i])
        if qsCount == 0 and sumdiff == 0:
            return False
        if qsCount % 2 == 1:
            return True
        if sumdiff == (-qsCount// 2) * 9:
            return False
        return True
