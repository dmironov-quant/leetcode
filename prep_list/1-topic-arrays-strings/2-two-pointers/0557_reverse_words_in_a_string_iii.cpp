// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            if (s[right] == ' ' || right == (int)s.size() - 1) {
                int i = left;
                int j = (right == (int)s.size() - 1) ? right : right - 1;
                while (j > i) {
                    swap(s[i], s[j]);
                    ++i;
                    --j;
                }
                left = right + 1;
            }
        }
        return s;
    }
};
