// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution {
public:
    vector<int> findAnagrams(const string& s, const string& p) {
        array<int, 26> p_freq;
        for (const char& letter : p) ++p_freq[letter - 'a'];
        int p_len = p.size();
        
        vector<int> ans;
        int n = s.size();
        array<int, 26> s_freq;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            ++s_freq[s[right] - 'a'];
            if (right - left + 1 == p_len) {
                if (s_freq == p_freq) ans.push_back(left);
                --s_freq[s[left] - 'a'];
                ++left;
            }
        }
        return ans;

    }
};
