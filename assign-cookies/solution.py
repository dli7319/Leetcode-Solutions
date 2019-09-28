class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        c = 0
        ct = 0
        for i in range(len(g)):
            while (c < len(s)):
                if (g[i] <= s[c]):
                    c+=1
                    ct+=1
                    break
                c+=1
        return ct
