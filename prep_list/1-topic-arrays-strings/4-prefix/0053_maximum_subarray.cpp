class Solution {
public:
    int maxSubArray(const vector<int>& a) {
        int ans = a[0];
        int curr = a[0];
        for (size_t i = 1; i < a.size(); ++i) {
            curr = max(curr + a[i], a[i]);
            ans  = max(ans, curr);
        }
        return ans;
    }
};
