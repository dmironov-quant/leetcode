// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

class Solution {
public:
    int maxConsecutiveAnswers(const string& a, int k) {
        int n = (int)a.size();
        int max_length = 0;
        int left = 0;
        int cnt_T = 0;
        int cnt_F = 0;
        for (int right = 0; right < n; ++right) {
            if (a[right] == 'T') ++cnt_T;
            else ++cnt_F;
            while (min(cnt_T, cnt_F) > k) {
                if (a[left] == 'T') --cnt_T;
                else --cnt_F;
                ++left;
            }
            if (min(cnt_T, cnt_F) <= k) {
                max_length = max(max_length, right - left + 1);
            }
        }
        return max_length;
    }
};
