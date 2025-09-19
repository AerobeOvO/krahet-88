class Solution1:
    def findMin(self, nums: List[int]) -> int:
        flag =1
        i = len(nums)

        for j in range(0, i-1):
            if nums[j]> nums[j+1]:
                return nums[j+1]
        
        return nums[0]


class Solution2:
    def findMin(self, nums: [int]) -> int:
        i, j = 0, len(nums) - 1
        while i < j:
            m = (i + j) // 2
            if nums[m] > nums[j]: i = m + 1
            elif nums[m] < nums[j]: j = m
            else: j -= 1
        return nums[i]