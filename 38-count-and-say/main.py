from collections import Counter
class Solution:
    def countAndSay(self, n: int) -> str:
        i = 1
        arr = "1"
        resArr = "1"
        while i < n:
            k = 0
            resArr = ""
            while k < len(arr):
                count = 1
                while k < len(arr) - 1  and arr[k] == arr[k + 1]:
                    count += 1
                    k += 1
                resArr += str(count) + arr[k]
                k += 1
            arr = resArr
            i += 1
        return arr


        
