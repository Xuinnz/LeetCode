class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        count = 0
        i = 0
        j = -1
        n = len(matrix) - 1
        m = len(matrix[0]) - 1
        length = (n + 1) * (m + 1)
        k = 0

        while count < length:
            j += 1
            while j <= m - k:
                if count >= length: break
                res.append(matrix[i][j])
                count += 1
                if j == m - k: break
                j += 1
            i += 1
            while i <= n - k:
                if count >= length: break
                res.append(matrix[i][j])
                count += 1
                if i == n - k: break
                i += 1
            j -= 1
            while j >= 0 + k:
                if count >= length: break
                res.append(matrix[i][j])
                count += 1
                if j == 0 + k: break
                j -= 1
            i -= 1
            k += 1
            while i >= 0 + k:
                if count >= length: break
                res.append(matrix[i][j])
                count += 1
                if i == 0 + k: break
                i -= 1
        return res
            
