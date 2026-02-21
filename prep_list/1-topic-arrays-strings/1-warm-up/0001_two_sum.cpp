// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(const vector<int>& a, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < (int)a.size(); ++i) {
            auto it = seen.find(target - a[i]);
            if (it != seen.end()) {
                return {i, it->second};
            }
            seen[a[i]] = i;
        }
        return {};
    }
};
