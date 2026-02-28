// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/?envType=daily-question&envId=2026-02-28

class Solution {
public:
    long long fastPow(long long x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x % MOD;
        if (n % 2 == 0) {
            long long num = fastPow(x, n / 2) % MOD;
            return (num * num) % MOD;
        }
        return (x * fastPow(x, n - 1)) % MOD;
    }

    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int length = 0;
            int x = i;
            while (x) {
                x >>= 1;
                ++length;
            }
            ans *= pow(2, length);
            ans += i;
            ans %= MOD;
        }
        return ans; 
    }

private:
    const int MOD = 1'000'000'007;
};
