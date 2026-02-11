class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1
        negative = False
        if n < 0:
            n = abs(n)
            negative = True
        while n > 0:
            if n % 2 == 1:
                res = res * x
            x = x * x
            n = n // 2
        if negative:
            return 1 / res
        return res
            
        
