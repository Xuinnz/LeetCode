class Solution:
    def totalNQueens(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2 or n == 3:
            return 0
        queens =[] #valid n-queens positioning
        queen = [] #queen state finding
        def backtrack(row, queen):
            if row == n: #if same row and n, valid and append
                queens.append(list(queen))
            for i in range(n): # i is the column
                if isValid(row, i, queen):
                    queen.append(i)
                else:
                    continue
                backtrack(row + 1, queen)
                queen.pop()

        def isValid(row, column, queen):
            for old_row, old_col in enumerate(queen):
                #if in same column
                if column == old_col:
                    return False
                #major diagonal check
                if old_row - old_col == row - column:
                    return False
                #minor diagonal check
                if old_row + old_col == row + column:
                    return False
            return True
        backtrack(0, [])
        #for printing
        return len(queens)

