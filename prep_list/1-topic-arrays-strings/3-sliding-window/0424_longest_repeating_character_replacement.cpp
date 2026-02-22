// https://leetcode.com/problems/longest-repeating-character-replacement/description/

// class Solution {
// public:
//     bool is_balance(const unordered_map<char, int>& counter, int k) {
//         int max_counter = 0;
//         int sum = 0;
//         for (const auto& [ch, cnt] : counter) {
//             sum += cnt;
//             max_counter = max(max_counter, cnt);
//         }
//         return sum - max_counter <= k;
//     }

//     int characterReplacement(const string& s, int k) {
//         int n = s.size();
//         int ans = 0;
//         unordered_map<char, int> counter;
//         int left = 0;
//         for (int right = 0; right < n; ++right) {
//             ++counter[s[right]];
//             while (!is_balance(counter, k)) {
//                 --counter[s[left++]];
//             }
//             ans = max(ans, right - left + 1);
//         }
//         return ans;
//     }
// };


class Solution {
public:

    int characterReplacement(const string& s, int k) {
        int n = s.size();
        int ans = 0;
        int max_freq = 0;
        unordered_map<char, int> counter;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            max_freq = max(max_freq, ++counter[s[right]]);
            while ((right - left + 1) - max_freq > k) {
                --counter[s[left++]];
            }
            ans = max(ans, right - left + 1); 
        }
        return ans;
    }
};
