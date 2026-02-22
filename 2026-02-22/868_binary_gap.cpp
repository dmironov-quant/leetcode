// https://leetcode.com/problems/binary-gap/description/?envType=daily-question&envId=2026-02-22

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1;
        int k = 0;
        while (n) {
            if (n & 1 == 1) {
                if (prev == -1) {
                    prev = k;
                } else {
                    ans = max(ans, k - prev);
                    prev = k;
                }
            }
            n >>= 1;
            ++k;
        }
        return ans;
    }
};
