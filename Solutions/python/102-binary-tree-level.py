class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        q=collections.deque()
        q.append(root)
        result=[]
        while q:
            qlen=len(q)
            level=[]
            for i in range(qlen):
                node=q.popleft()

                if node:
                    level.append(node.val)
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
            if level:
                result.append(level)
        return result
        
        #Time Complexity :O(N)
        #Space Complexity:O(N)
        
