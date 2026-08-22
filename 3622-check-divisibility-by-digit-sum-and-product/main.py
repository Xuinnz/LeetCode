class Solution:
    def checkDivisibility(self, n: int) -> bool:
        dSum = 0
        dProd = 1
        m = n
        while m >= 1:
            i = m % 10
            dSum += i
            dProd *= i 
            m = m // 10
        if n % (dProd + dSum) == 0:
            return True
        return False
