// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2026-03-04

class Solution {
public:
    int numSpecial(const vector<vector<int>>& mat) {
        int cnt = 0;
        int m = mat.size();
        int n = mat[0].size();
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (mat[row][col] == 1) {
                    bool flag = false;
                    for (int i = 0; i < m; ++i) {
                        if (i != row && mat[i][col] == 1) {
                            flag = true;
                        }
                    }
                    for (int j = 0; j < n; ++j) {
                        if (j != col && mat[row][j] == 1) {
                            flag = true;
                        }
                    }
                    if (!flag) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};
