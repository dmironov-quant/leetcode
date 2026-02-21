// https://leetcode.com/problems/contains-duplicate-ii/description/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        unordered_map<int, int> seen;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (seen.count(a[i]) > 0) {
                if (i - seen[a[i]] <= k) {
                    return true;
                }
            }
            seen[a[i]] = i;
        }
        return false;
    }
};
