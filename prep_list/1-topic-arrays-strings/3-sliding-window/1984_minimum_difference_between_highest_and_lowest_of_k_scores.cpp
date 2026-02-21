// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/

class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int n = a.size();
        sort(begin(a), end(a));
        int min_diff = numeric_limits<int>::max();
        int left = 0;
        for (int right = k - 1; right < n; ++right) {
            min_diff = min(min_diff, a[right] - a[left++]);
        }
        return min_diff; 
    }
};
