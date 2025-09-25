# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        path, res =[], []
        def sumOfPath(root, targetSum):
            if not root: return

            path.append(root.val)

            if not root.left and not root.right and sum(list(path)) == targetSum:
                res.append(list(path))

        
            sumOfPath(root.left, targetSum)
            sumOfPath(root.right, targetSum)
            path.pop()

        sumOfPath(root,targetSum)    
        return res

        


        