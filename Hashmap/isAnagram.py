class Solution:
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        dic = defaultdict(int)
        for c in s:
            dic[c] += 1
        for c in t:
            dic[c] -= 1
        for val in dic.values(): #1
            if val != 0:
                return False
        return True
