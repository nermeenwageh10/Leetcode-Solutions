# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode] , val = 0) -> int:
        if not root:
            return 0
        q = [root]
        sum = 0
        while(q):
            node  = q.pop()
            if not node.left and not node.right:
                sum+=node.val
            
            if node.left:
                node.left.val += node.val*10
                q.append(node.left)
            if node.right:
                node.right.val += node.val*10
                q.append(node.right)
        return sum



