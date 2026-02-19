// https://leetcode.com/problems/count-binary-substrings/submissions/1923837325/?envType=daily-question&envId=2026-02-19

class Solution {
public:
    int countBinarySubstrings(const string& s) {
        int n = s.size();
        int ans = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            while (right < n && s[right] == s[left]) ++right;
            int first_kind = right - left;
            int start_right = right;
            while (right < n && s[right] == s[start_right]) ++right;
            int second_kind = right - start_right;
            ans += min(first_kind, second_kind);
            left = start_right;
        }
        return ans;
    }
};
