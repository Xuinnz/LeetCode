class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        arr = []
        for i in range(m):
            st = ""
            if i == m - 1:
                st = "." * n
            else:
                for i in range(n):
                    if i == 0:
                        st += "."
                    else:
                        st += "#"
            arr.append(st)
        return arr
