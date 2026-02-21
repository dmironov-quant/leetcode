// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/?envType=daily-question&envId=2026-02-21


class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> is_prime(33, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for (int i = 2; i < (int)is_prime.size(); ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j < (int)is_prime.size(); j += i) {
                    is_prime[j] = false;
                }
            }
        }
        int ans = 0;
        for (int i = left; i < right + 1; ++i) {
            int ones = 0;
            int num = i;
            while (num) {
                int x = num & 1;
                if (x == 1) ++ones;
                num >>= 1;
            }
            if (ones < right + 1 && is_prime[ones]) ++ans;
        }
        return ans;
    }
};
