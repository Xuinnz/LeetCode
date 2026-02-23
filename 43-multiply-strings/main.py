class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        count1 = len(num1) - 1
        count2 = len(num2) - 1
        midArr = []
        res = ""
        remainder = 0
        #put all product in midArr
        while count2 >= 0:
            count1 = len(num1) - 1
            remainder = 0
            midNum = ""
            while count1 >= 0:
                prod = int(num1[count1]) * int(num2[count2]) + remainder
                remainder = prod // 10
                prod = prod % 10
                midNum = str(prod) + midNum
                count1 -= 1
            if remainder:
                midNum = str(remainder) + midNum
            
            midNum = midNum + ("0" * (len(num2) - 1 - count2))
            midArr.append(midNum)
            count2 -= 1
        #use zfill for column by column adding
        max_len = len(midArr[-1])
        for i in range(len(midArr)):
            midArr[i] = midArr[i].zfill(max_len)
        
        # add all numbers in the midArr
        res = ""
        resCount = max_len - 1
        remainder = 0
        midCount = len(midArr)
        
        while resCount >= 0:
            sumRes = remainder
            for i in range(midCount):
                sumRes += int(midArr[i][resCount])
            
            remainder = sumRes // 10
            sumRes = sumRes % 10
            res = str(sumRes) + res
            resCount -= 1
            
        if remainder:
            return str(remainder) + res
        return res
        
