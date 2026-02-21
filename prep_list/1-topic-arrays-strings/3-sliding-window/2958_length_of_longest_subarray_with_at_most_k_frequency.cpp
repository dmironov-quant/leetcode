// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

class Solution {
public:
    int maxSubarrayLength(const vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> counter;
        int max_length = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            ++counter[a[right]];
            while (counter[a[right]] > k) {
                --counter[a[left++]];
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};
