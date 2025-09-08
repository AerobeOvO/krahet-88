class Solution(object):
    def isIsomorphic(self, s, t):
        s2t, t2s = {}, {}
        for a, b in zip(s, t):
            if a in s2t and s2t[a] != b or \
               b in t2s and t2s[b] != a:
                return False
            s2t[a], t2s[b] = b, a
        return True

        
