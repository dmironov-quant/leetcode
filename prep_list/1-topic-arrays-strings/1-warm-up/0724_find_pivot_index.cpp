// https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n = a.size();
        if (n == 1) {
            return 0;
        }
        
        vector<int> pref_sum(n, 0);
        pref_sum[0] = a[0];
        for (int i = 1; i < n; ++i) pref_sum[i] = pref_sum[i - 1] + a[i];
        
        vector<int> suf_sum(n, 0);
        suf_sum[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) suf_sum[i] = suf_sum[i + 1] + a[i];

        int pivot = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            if (i == 0 && suf_sum[i + 1] == 0) pivot = min(pivot, i);
            if (i == n - 1 && pref_sum[i - 1] == 0) pivot = min(pivot, i);
            if (i != 0 && i != n - 1 && pref_sum[i - 1] == suf_sum[i + 1]) pivot = min(pivot, i);
        }

        return (pivot == numeric_limits<int>::max()) ? -1 : pivot;
    }
};
