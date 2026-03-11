// https://leetcode.com/problems/complement-of-base-10-integer/?envType=daily-question&envId=2026-03-11

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        vector<int> digits;
        while (n) {
            int x = n % 2;
            digits.push_back(x ^ 1);
            n >>= 1;
        }
        int ans = 0;
        for (int i = (int)digits.size() - 1; i >= 0; --i) {
            ans = (ans << 1) + digits[i];
        }
        return ans;
    }
};
