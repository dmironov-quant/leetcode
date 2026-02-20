// https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string& s) {
        vector<string> ans;
        unordered_map<string, int> freq;
        for (int left = 0; left + 10 <= (int)s.size(); ++left) {
            string t = s.substr(left, 10);
            ++freq[t];
            if (freq[t] == 2) ans.push_back(t);
        }
        return ans;
    }
};
