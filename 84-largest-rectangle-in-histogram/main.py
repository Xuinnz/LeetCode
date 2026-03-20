class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        #index
        #[0, 1, 2, 3, 4, 5]
        #height
        #[2, 1, 5, 6, 2, 3]
        #[1, 5, 6]
        stack = []
        maxArea = 0
        heights.append(0)

        for i, h in enumerate(heights):
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                maxArea = max(maxArea, height * widtah)
            stack.append(i)
        heights.pop()
        return maxArea
        
