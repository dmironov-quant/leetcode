// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

class Solution {
public:
    long long countSubarrays(const vector<int>& a, long long k) {
        int n = a.size();
        long long ans = 0;
        long long sum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += a[right];
            while (sum * (right - left + 1) >= k) {
                sum -= a[left++];
            }
            if (sum * (right - left + 1) < k) {
                ans += (long long)right - left + 1;
            }
        }
        return ans;
    }
};
