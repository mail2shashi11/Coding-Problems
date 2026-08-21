class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        
        // If total sum is odd, equal partition is impossible
        if (sum % 2 != 0) return false;
        
        int n = nums.size();
        int target = sum / 2;
        
        // dp[i][j]: can we form sum 'j' using the first 'i' numbers?
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // Target sum of 0 is always possible
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            int curr_num = nums[i - 1];
            for (int j = 1; j <= target; j++) {
                if (j < curr_num) {
                    dp[i][j] = dp[i - 1][j]; // Exclude current number
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - curr_num]; // Exclude || Include
                }
            }
        }
        
        return dp[n][target];

    }
};