class Solution:
    def backtrack(state: list[int], choices: list[int], selected: list[bool], res: list[list[int]]) -> List[List[int]]:
        if len(state) == len(choices):
            res.append(list(state))
            return
        for i, choice in enumerate(choices):
            if not selected[i]:
                selected[i] = True
                state.append(choice)
                backtrack(state, choices, selected, res)
                selected[i] = False
                state.pop()

    def permute(self, nums: List[int]) -> List[List[int]]:
        res=[]
        backtrack(state=[], choices= nums, selected=[False], res=res)
        return res
        

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(x):
            if x == len(nums) - 1:
                res.append(list(nums))   # 添加排列方案
                return
            for i in range(x, len(nums)):
                nums[i], nums[x] = nums[x], nums[i]  # 交换，将 nums[i] 固定在第 x 位
                dfs(x + 1)                           # 开启固定第 x + 1 位元素
                nums[i], nums[x] = nums[x], nums[i]  # 恢复交换
        res = []
        dfs(0)
        return res