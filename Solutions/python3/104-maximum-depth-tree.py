class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def rec(node,s):
            if node is None:
                return s
            return max(rec(node.left,s+1),rec(node.right,s+1))
        maxs=rec(root,0)
        return maxs
      #Time Complexity :O(N)
      #Space Complexity:O(1)
