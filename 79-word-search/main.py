class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])
        state = 0
        count = len(word)
        def check(state, i, j, used):
            if i >= n or i < 0 or j >= m or j < 0 or word[state] != board[i][j]:
                return False
            if state == count - 1:
                return True
            if (i + 1, j) not in used:
                used.add((i + 1, j))
                if check(state + 1, i + 1, j, used): return True
                used.remove((i + 1, j))
            if (i - 1, j) not in used:
                used.add((i - 1, j))
                if check(state + 1, i - 1, j, used): return True
                used.remove((i - 1, j))
            if (i, j + 1) not in used:
                used.add(((i, j + 1)))
                if check(state + 1, i, j + 1, used): return True
                used.remove(((i, j + 1)))
            if (i, j - 1) not in used:
                used.add(((i, j - 1)))
                if check(state + 1, i, j - 1, used): return True
                used.remove(((i, j - 1)))
        for i in range(n):
            for j in range(m):
                if word[0] == board[i][j]:
                    if check(0, i, j, {(i, j)}): return True
        return False