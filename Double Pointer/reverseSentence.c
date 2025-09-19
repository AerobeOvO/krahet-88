class Solution(object):
    def reverseWords(self, s):
        s= s.strip()
        j = len(s)-1
        i =j
        word =[]

        while i >= 0:
            while i >= 0 and s[i] != ' ': i -= 1
            word.append(s[i + 1: j + 1])         
            while i >= 0 and s[i] == ' ': i -= 1 
            j = i                       
        return ' '.join(word)  
