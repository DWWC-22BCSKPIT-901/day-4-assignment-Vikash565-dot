#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int longestSubsequence(vector<int>& nums, int k) {
    map<int, int> dp;  // Map to store the longest subsequence ending at a specific value
    int maxLength = 0;

    for (int num : nums) {
        int maxPrev = 0;
        for (int x = num - k; x <= num - 1; ++x) {
            if (dp.count(x)) {
                maxPrev = max(maxPrev, dp[x]);
            }
        }
        dp[num] = maxPrev + 1;
        maxLength = max(maxLength, dp[num]);
    }

    return maxLength;
}

int main() {
    vector<int> nums1 = {4, 2, 1, 4, 3, 4, 5, 8, 15};
    int k1 = 3;
    cout << "Example 1 Output: " << longestSubsequence(nums1, k1) << endl;

    vector<int> nums2 = {7, 4, 5, 1, 8, 12, 4, 7};
    int k2 = 5;
    cout << "Example 2 Output: " << longestSubsequence(nums2, k2) << endl;

    return 0;
}
