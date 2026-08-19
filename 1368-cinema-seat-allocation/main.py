class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:

        ans = n * 2
        row_hash = {}
        for row, seat in reservedSeats:
            if seat == 1 or seat == 10:
                continue
            if row not in row_hash:
                row_hash[row] = 0
            if seat == 2 or seat == 3:
                row_hash[row] |= 8
            elif seat == 4 or seat == 5:
                row_hash[row] |= 4
            elif seat == 6 or seat == 7:
                row_hash[row] |= 2
            elif seat == 8 or seat == 9:
                row_hash[row] |= 1
        
        for mask in row_hash.values():
            if (mask & 3) == 0 or (mask & 6) == 0 or (mask & 12) == 0:
                ans -= 1
            else:
                ans -= 2
        return ans

# 1 0 0 0 - 8
# 0 1 0 0 - 4
# 0 0 1 0 - 2
# 0 0 0 1 - 1

# [Y N N   Y N N N  N Y N ]
# [Y N N   N N Y Y  Y Y N ]
