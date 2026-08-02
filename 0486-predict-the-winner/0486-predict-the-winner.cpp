class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // Base case: Subarray of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Build DP table for lengths 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};