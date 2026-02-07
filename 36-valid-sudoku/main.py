class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [set() for _ in range(9)]
        column = [set() for _ in range(9)]
        box = [set() for _ in range(9)]

        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == '.': continue
                boxIndex = (r //3 ) * 3 + (c // 3)
                if val in row[r] or val in column[c] or val in box[boxIndex]:
                    return False
                row[r].add(val)
                column[c].add(val)
                box[boxIndex].add(val)
        return True
        