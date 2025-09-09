class Solution(object):
    def twoSum(self, numbers, target):
        i =0
        j = len(numbers)- 1

        while i != j:
            if target -numbers[j] > numbers[i]:
                i +=1
            elif target -numbers[j] < numbers[i]:
                j -=1
            
            else: return [i+1,j+1]