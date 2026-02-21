// https://leetcode.com/problems/k-radius-subarray-averages/

class Solution {
public:
    vector<int> getAverages(const vector<int>& a, int k) {
        int n = a.size();
        vector<int> ans(n, -1);
        uint64_t sum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += (uint64_t)a[right];
            if (right - 2 * k >= 0 && right - k < n) {
                ans[right - k] = sum / (2 * k + 1);
                sum -= a[left++];
            }
        }
        return ans;
    }
};
