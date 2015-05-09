# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return nothing, do it in place
    def flatten(self, root):
        if root is None:
            return
        stk = []
        while True:
            if root.right is not None:
                stk.append(root.right)
            if root.left is not None:
                root.right = root.left
                root.left = None
                root = root.right
            else:
                if len(stk) == 0: return
                root.right = stk.pop()
                root = root.right