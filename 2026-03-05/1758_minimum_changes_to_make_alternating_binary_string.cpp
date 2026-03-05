// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/?envType=daily-question&envId=2026-03-05

class Solution {
public:
    int minOperations(string s) {
        string opt1 = "1";
        for (size_t i = 1; i < s.size(); ++i) {
            if (opt1.back() == '1') opt1 += '0';
            else opt1 += '1';
        }
        string opt2 = "0";
        for (size_t i = 0; i < s.size(); ++i) {
            if (opt2.back() == '0') opt2 += '1';
            else opt2 += '0';
        }
        int ans1 = 0;
        int ans2 = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != opt1[i]) ++ans1;
            if (s[i] != opt2[i]) ++ans2;
        }
        return min(ans1, ans2);
    }
};
