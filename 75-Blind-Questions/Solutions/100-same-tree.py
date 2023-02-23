class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:

        def rec(node1,node2):
            if not node1 and not node2:
                return True 
            elif not node1 and node2 or not node2 and node1:
                return False 
            elif node1.val != node2.val :
                return False 
            else:
                return rec(node1.left,node2.left ) and rec(node1.right,node2.right)
        return(rec(p,q))
        
        #Time Complexity :O(N)
        #Space Complexity:O(1)
