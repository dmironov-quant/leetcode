class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& a) {
        int n = a.size();
        vector<int> prefix(n, 1);
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * a[i - 1];
        }
        vector<int> ans(n);
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = prefix[i] * suffix;
            suffix *= a[i];
        }
        return ans;
    }
};
