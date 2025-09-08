class Solution:
    def longestPalindrome(self, s: str) -> int:
        counter = collections.defaultdict(int)
        for c in s:
            counter[c] += 1
        res, odd = 0, 0
        for count in counter.values():
            rem = count % 2
            res += count - rem

            if rem == 1: odd = 1
        return res + odd