// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));
        int ans = 0;
        int i = 0, j = 0;
        while (i < (int)players.size() && j < (int)trainers.size()) {
            if (players[i] <= trainers[j]) {
                ++i;
                ++ans;
            }
            ++j;
        }
        return ans;
    }
};
