// https://leetcode.com/problems/3sum-with-multiplicity/description/

class Solution {
public:
    int threeSumMulti(const vector<int>& arr, int target) {
        int ans = 0;
        int n = arr.size();
        const int MOD = 1'000'000'000 + 7;
        vector<int> freq(101, 0);
        for (int i = 0; i < n; ++i) ++freq[arr[i]];
        for (int i = 0; i < n; ++i) {
            vector<int> seen(101, 0);
            ++seen[arr[i]];
            for (int j = i + 1; j < n; ++j) {
                ++seen[arr[j]];
                int num = target - arr[i] - arr[j];
                int cnt = 0;
                if (0 <= num && num <= 100) cnt += freq[num] - seen[num];
                ans = (ans + cnt) % MOD;
            }
        }
        return ans / 2;
    }
};
