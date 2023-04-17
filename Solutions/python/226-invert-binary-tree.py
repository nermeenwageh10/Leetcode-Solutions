class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        def rec(node):
            if node is None:
                return
            tempnode=node.left
            node.left=node.right
            node.right=tempnode
            rec(node.left)
            rec(node.right)
        rec(root)
        return root
      
      #Time Complexity :O(N)
      #Space Complexity:O(1)
