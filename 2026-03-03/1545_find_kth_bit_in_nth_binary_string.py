// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/?envType=daily-question&envId=2026-03-03

class Solution:
    def invertBit(self, t: str) -> str:
        x = ""
        for ch in t:
            if ch == '0': x += '1'
            if ch == '1': x += '0'
        return x[::-1]

    def findKthBit(self, n: int, k: int) -> str:
        s = "0"
        for i in range(1, n):
            s = s + '1' + self.invertBit(s)
        return s[k-1]
