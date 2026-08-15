class Solution:
    def maxProduct(self, n: int) -> int:
        firstDigit = 0
        secondDigit = 0

        while n != 0:
            mod = n % 10
            if firstDigit == 0:
                firstDigit = mod
            elif mod >= firstDigit:
                if firstDigit >= secondDigit:
                    secondDigit = firstDigit
                firstDigit = mod
            elif mod >= secondDigit:
                secondDigit = mod
            n = n // 10
        return firstDigit * secondDigit

