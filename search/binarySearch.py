class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i = len(nums)

        if target < nums[i//2]:
            search(nums[0:i//2], target)
        elif target > nums[i//2]:
            search(nums[i//2:i], target)
        else: return i//2

        return -1
    

# or

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target in nums :
            return nums.index(target)
        else:
            return -1