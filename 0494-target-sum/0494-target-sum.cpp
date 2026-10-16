#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        
        // Check if target is achievable
        if (total_sum < std::abs(target) || (total_sum - target) % 2 != 0) {
            return 0;
        }
        
        int n = (total_sum - target) / 2;
        
        // dp[j] stores the number of ways to get a subset sum of j
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: 1 way to make sum 0
        
        for (int num : nums) {
            for (int j = n; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[n];
    }
};