// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/

class Solution {
public:
    int minimumDeletions(const vector<int>& a) {
        auto [itMin, itMax] = std::minmax_element(begin(a), end(a));
        auto iMin = std::distance(begin(a), itMin);
        auto iMax = std::distance(begin(a), itMax);
        auto size = (int)a.size();
        int ans = min(
            min((1 + iMin) + (size - iMax), 1 + max(iMax, iMin)), 
            min((1 + iMax) + (size - iMin), size - min(iMax, iMin))
        );
        return ans;
    }
};
