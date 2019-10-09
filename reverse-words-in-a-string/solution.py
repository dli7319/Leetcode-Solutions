class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(filter(None, s.split(' ')[::-1]))
