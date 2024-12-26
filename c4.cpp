#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums, int k) {
        map<int, int> dp;

        int maxLength = 0;

        for (int num : nums) {
            int maxPrev = 0;

            auto start = dp.lower_bound(num - k);
            auto end = dp.upper_bound(num - 1);

            for (auto it = start; it != end; ++it) {
                maxPrev = max(maxPrev, it->second);
            }

            dp[num] = maxPrev + 1;
            maxLength = max(maxLength, dp[num]);
        }

        return maxLength;
    }
};
