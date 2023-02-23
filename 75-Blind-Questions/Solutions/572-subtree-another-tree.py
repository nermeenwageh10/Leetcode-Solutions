class Solution:
    def subtree(self,node1,node2):
            if not node1 and not node2:
                return( True)
            if ( not node1 and node2) or (not node2 and node1 )or (node1.val !=node2.val):
                return( False)
            return(self.subtree(node1.left,node2.left) and self.subtree(node1.right,node2.right))
            
    def rec(self,root,subroot):
        if root is None:
            return False
        if self.subtree(root,subroot):
            return True
            
        else:
            return(self.rec(root.left,subroot) or 
            self.rec(root.right,subroot))

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        return(self.rec(root,subRoot))
        
        #Time Complexity :O(N)
        #Space Complexity:O(1)
        
