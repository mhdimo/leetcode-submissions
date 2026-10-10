class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        n1, n2 = len(s1), len(s2)

        c1 = [0] * 26
        c2 = [0] * 26

        for i in range(n1):
            c1[ord(s1[i]) - ord('a')] += 1
            c2[ord(s2[i]) - ord('a')] += 1

        if c1 == c2:
            return True

        for i in range(n1, n2):
            c2[ord(s2[i]) - ord('a')] += 1
            c2[ord(s2[i - n1]) - ord('a')] -= 1

            if c1 == c2:
                return True

        return False