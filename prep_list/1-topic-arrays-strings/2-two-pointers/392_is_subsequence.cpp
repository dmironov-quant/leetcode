// https://leetcode.com/problems/is-subsequence/description/

class Solution {
public:
    bool isSubsequence(const string& s, const string& t) {
        int i = 0, j = 0;
        while (i < (int)s.size() && j < (int)t.size()) {
            if (s[i] == t[j]) ++i;
            ++j;
        }
        return i == (int)s.size();
    }
};
