// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=daily-question&envId=2026-02-25

struct Number {
    int num = 0;
    int bits = 0;
};

class Solution {
public:
    int countOnes(int x) {
        int cnt = 0;
        while (x) {
            cnt += x & 1;
            x >>= 1;
        }
        return cnt;
    }

    vector<int> sortByBits(const vector<int>& a) {
        vector<Number> number;
        for (size_t i = 0; i < a.size(); ++i) {
            int bits = countOnes(a[i]);
            number.push_back({a[i], bits});
        }
        sort(begin(number), end(number), 
            [](const Number& lhs, const Number& rhs) {
                return (lhs.bits < rhs.bits) || (lhs.bits == rhs.bits && lhs.num < rhs.num);
        });
        vector<int> ans;
        for (size_t i = 0; i < number.size(); ++i) {
            ans.push_back(number[i].num);
        }
        return ans;
    }
};
