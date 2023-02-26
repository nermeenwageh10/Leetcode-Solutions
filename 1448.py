# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        maxval=root.val
        count=0
        def isgood(root,maxval):
            nonlocal count
            if root is None:
                return
            if root.val>= maxval:
                count+=1
                maxval=root.val
            isgood(root.left,maxval)
            isgood(root.right,maxval)
        isgood(root,maxval)
        return count
