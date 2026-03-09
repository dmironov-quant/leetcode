// https://leetcode.com/problems/xor-queries-of-a-subarray/description/

class Solution {
public:
    vector<int> xorQueries(const vector<int>& arr, const vector<vector<int>>& queries) {
        vector<int> pref;
        pref.push_back(arr[0]);
        for (size_t i = 1; i < arr.size(); ++i) {
            pref.push_back(arr[i] ^ pref.back());
        }
        vector<int> ans;
        for (size_t i = 0; i < queries.size(); ++i) {
            int left = queries[i][0];
            int right = queries[i][1];
            if (left == 0) {
                ans.push_back(pref[right]);
            }
            else {
                ans.push_back(pref[right] ^ pref[left - 1]);
            }
        }
        return ans;
    }
};
