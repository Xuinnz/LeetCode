class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        height = []
        n = len(matrix)
        m = len(matrix[0])
        maxArea = 0
        height = [0] * (m + 1)

        for i in range(n): #rows
            for j in range(m):#fill height
                if matrix[i][j] == "1":
                    height[j] += 1
                else:
                    height[j] = 0
            stack = []
            for j in range(m + 1):
                while stack and height[stack[-1]] > height[j]:
                    h = height[stack.pop()]
                    w = j if not stack else j - stack[-1] - 1
                    maxArea = max(maxArea, h * w)
                stack.append(j)
        return maxArea
        
