# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.match = 0

        def post_order(node):
            if not node:
                return 0, 0
            # left
            left_sum, left_count = post_order(node.left)
            # right
            right_sum, right_count = post_order(node.right)

            curr_sum = left_sum + right_sum + node.val
            curr_count = right_count + left_count + 1
            if (curr_sum // curr_count) == node.val:
                self.match += 1 
            return curr_sum, curr_count
        post_order(root)
        return self.match
        
