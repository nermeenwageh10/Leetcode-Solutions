class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        lastvalue=float('-inf')
        statment=True
        def dfs(node):
            nonlocal statment,lastvalue
            if node is None:
                return 
            dfs(node.left)
            if node.val > lastvalue:
                lastvalue=node.val
            else:
                statment=False
            dfs(node.right)
        dfs(root)
        return statment
        
        #Time Complexity :O(N)
        #Space Complexity:O(1)
