// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/?envType=daily-question&envId=2026-02-23
// can be also solved by using rolling hash or bitmasks

class Solution {
public:
    bool hasAllCodes(const string& s, int k) {
        unordered_set<string> seen;
        for (int i = 0; i < (int)s.size(); ++i) {
            string t = s.substr(i, k);
            if ((int)t.size() == k) seen.insert(t);
        }
        return (int)seen.size() == pow(2, k);
    }
};
