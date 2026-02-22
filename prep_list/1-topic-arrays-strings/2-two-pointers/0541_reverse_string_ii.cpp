// https://leetcode.com/problems/reverse-string-ii/description/

class Solution {
public:
    string reverseStr(const string& s, int k) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i += 2*k) {
            string r;
            for (int j = i; j < min(n, i + k); ++j) r += s[j];
            reverse(begin(r), end(r));
            ans += r;
            string f;
            for (int j = i + k; j < min(n, i + 2*k); ++j) f += s[j];
            ans += f;
        }
        return ans;
    }
};
