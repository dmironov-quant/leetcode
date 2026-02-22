// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        array<int, 26> s_freq, t_freq;
        for (size_t i = 0; i < s.size(); ++i) ++s_freq[s[i] - 'a'];
        for (size_t i = 0; i < t.size(); ++i) ++t_freq[t[i] - 'a'];
        return s_freq == t_freq;
    }
};
