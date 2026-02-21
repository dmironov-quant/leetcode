// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        int ans = 0;
        unordered_map<char, int> seen;
        int left = 0;
        int length = (int)s.size();
        for (int right = 0; right < length; ++right) {
            ++seen[s[right]];
            while (seen[s[right]] > 1) {
                --seen[s[left]];
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
