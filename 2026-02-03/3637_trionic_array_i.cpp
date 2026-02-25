// https://leetcode.com/problems/trionic-array-i/submissions/1906053343/?envType=daily-question&envId=2026-02-03

class Solution {
public:
    bool isTrionic(const vector<int>& a) {
        int n = a.size();
        int p = 0;
        for (; p < n - 1; ++p) {
            if (a[p + 1] <= a[p]) {
                break;
            }
        }
        if (p <= 0) return false;
        if (p > n - 3) return false;
        int q = n - 1;
        for (; q >= 0; --q) {
            if (a[q-1] >= a[q]) {
                break;
            }
        }
        if (q >= n - 1) return false;
        if (p >= q) return false;
        for (int i = p + 1; i <= q; ++i) {
            if (a[i] >= a[i-1]) {
                return false;
            }
        }
        return true;
    }
};
