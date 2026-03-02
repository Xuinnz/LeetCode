class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0] * n for _ in range(n)]
        count = 0
        length = n * n 
        i = 0
        j = 0
        k = 0
        while count < length:
            while j < n - k:
                if count >= length: break
                res[i][j] = count + 1
                count += 1
                if j == n - k - 1: break
                j += 1
            i += 1
            while i < n - k:
                if count >= length: break
                res[i][j] = count + 1
                count += 1
                if i == n - k- 1: break
                i += 1
            j -= 1
            while j >= 0 + k:
                if count >= length: break
                res[i][j] = count + 1
                count += 1
                if j == 0 + k: break
                j -= 1
            i -= 1
            k += 1
            while i >= 0 + k:
                if count >= length: break
                res[i][j] = count + 1
                count += 1
                if i == 0 + k: break
                i -= 1
            j += 1
        return res

