class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        dic = {}
        for i in A:
            if i in dic:
                return i
            else:
                dic.update({i: True})
