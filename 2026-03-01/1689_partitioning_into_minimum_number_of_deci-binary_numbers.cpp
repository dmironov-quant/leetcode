// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/?envType=daily-question&envId=2026-03-01

class Solution {
public:
    int minPartitions(string str) {
        int max_num = 0;
        for (size_t i = 0; i < str.size(); ++i) {
            max_num = max(max_num, (int)(str[i] - '0'));
        }
        return max_num;
    }
};
