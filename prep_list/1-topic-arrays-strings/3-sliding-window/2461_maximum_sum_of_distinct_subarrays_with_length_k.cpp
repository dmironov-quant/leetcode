// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution {
public:
    long long maximumSubarraySum(const vector<int>& a, int k) {
        long long max_sum = 0;
        long long sum = 0;
        int n = a.size();
        unordered_map<int, int> freq;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += a[right];
            ++freq[a[right]];
            while (right - left + 1 > k || freq[a[right]] > 1) {
                --freq[a[left]];
                sum -= a[left];
                ++left;
            }
            if (right - left + 1 == k) {
                max_sum = max(max_sum, sum);
            }
        }
        return max_sum;
    }
};
