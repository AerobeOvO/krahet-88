# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue: deque[TreeNode] = deque()
        queue.append(root)
        res = []
        i =0
        while queue:
            tmp = deque()
            for _ in range(len(queue)):
                node = queue.popleft()
                if len(res) % 2 == 0: tmp.append(node.val)
                else: tmp.appendleft(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            res.append(list(tmp)) #convert to list
        return res