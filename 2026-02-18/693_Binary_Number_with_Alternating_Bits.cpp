// 2026-02-18
// daily question
// https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        n >>= 1;
        while (n) {
            int curr = n & 1;
            if (curr == 0 && prev == 0) return false;
            if (curr == 1 && prev == 1) return false;
            n >>= 1;
            prev = curr;
        }
        return true;
    }
};
