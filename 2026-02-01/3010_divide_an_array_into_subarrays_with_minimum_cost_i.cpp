// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01

class Solution {
public:
    int minimumCost(const vector<int>& a) {
        // a[m1] <= a[m2] <= a[m3]
        int m1 = 0;
        int m2 = 1;
        int m3 = 2;
        if (a[m1] >= a[m2]) swap(m1, m2);
        if (a[m1] >= a[m3]) swap(m1, m3);
        if (a[m2] >= a[m3]) swap(m2, m3);
        for (int i = 3; i < (int)a.size(); ++i) {
            if (a[i] <= a[m1]) {
                m3 = m2;
                m2 = m1;
                m1 = i;
            }
            else if (a[i] <= a[m2]) {
                m3 = m2;
                m2 = i;
            }
            else if (a[i] < a[m3]) {
                m3 = i;
            }
        }
        if (m1 >= m2) swap(m1, m2);
        if (m1 >= m3) swap(m1, m3);
        if (m2 >= m3) swap(m2, m3);
        int ans = a[0] + a[m2] + a[m3];
        if (m1 != 0) {
            ans = min(ans, a[0] + a[m1] + a[m2]);
            ans = min(ans, a[0] + a[m1] + a[m3]);
        }
        return ans;
    }
};
