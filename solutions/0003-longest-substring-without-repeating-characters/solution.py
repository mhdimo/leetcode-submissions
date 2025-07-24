class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxl=0
        left=0
        lastseen = {}

        for right, c in enumerate(s):
            if c in lastseen and lastseen[c] >= left:
                left = lastseen[c]+1

            maxl = max(maxl, right- left + 1)
            lastseen[c] = right
            
        return maxl