// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, const vector<int>& a) {
        int n = a.size();
        int min_length = numeric_limits<int>::max();
        int curr_sum = 0;
        int right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n && curr_sum < target) {
                curr_sum += a[right++];
            }
            if (curr_sum >= target) {
                min_length = min(min_length, right - left);
            }
            curr_sum -= a[left];
        }
        return (min_length == numeric_limits<int>::max()) ? 0 : min_length;
    }
};
