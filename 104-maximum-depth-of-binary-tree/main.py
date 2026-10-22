# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode | None) -> int:
        ans = 0
        def dfs(node, count):
            nonlocal ans
            if not node:
                return 
            ans = max(count, ans)
            dfs(node.left, count + 1)
            dfs(node.right, count + 1)
        dfs(root, 1)
        return ans
