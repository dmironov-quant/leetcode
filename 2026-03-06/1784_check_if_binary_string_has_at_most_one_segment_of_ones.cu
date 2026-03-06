// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/?envType=daily-question&envId=2026-03-06

class Solution {
public:
    bool checkOnesSegment(const string& s) {
        bool ones = true;
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == '1' && !ones) return false;
            if (s[i] == '0') ones = false;
        }
        return true;
    }
};
