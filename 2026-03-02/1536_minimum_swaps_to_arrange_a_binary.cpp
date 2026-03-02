// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/?envType=daily-question&envId=2026-03-02

const int zero = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minSwaps(const vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            vector<int> row = grid[i];
            int zeros = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (row[j] == 0) {
                    ++zeros;
                } 
                else {
                    break;
                }
            }
            cnt[i] = zeros;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int needed = n - i - 1;
            int pos = -1;
            for (int j = i; j < n; ++j) {
                if (cnt[j] >= needed) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) {
                return -1;
            }
            ans += abs(pos - i);
            for (int j = pos; j > 0; --j) {
                swap(cnt[j], cnt[j-1]);
            }
        }
        return ans;
    }
};
