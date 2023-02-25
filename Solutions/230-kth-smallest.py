class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        l=[]
        def node(root):
            if root is None:
                return 
            nonlocal l
            node(root.left)
            l.append(root.val)
            node(root.right)
        node(root)
        return(l[k-1])
      
      #Time Complexity :O(N)
      #Space Complexity:O(N)
