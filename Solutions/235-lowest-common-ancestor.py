
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if (p.val == root.val) or (q.val == root.val) or (p.val < root.val and root.val < q.val) or (q.val < root.val and root.val < p.val):
            return root
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return self.lowestCommonAncestor(root.right, p, q)
            
            
          #Time Complexity :O(logN)
          #Space Complexity:O(1)
            
       
