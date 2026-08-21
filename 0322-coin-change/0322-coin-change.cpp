class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, amount+1));

        for(int i=0; i<=n; i++) dp[i][0] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                int exc = dp[i-1][j];
                int inc = amount + 1;
                if(coins[i-1] <= j) inc = 1 + dp[i][j - coins[i-1]];
                dp[i][j] = min(inc, exc);
            }
        } 
        return dp[n][amount] > amount ? -1 : dp[n][amount];
    }
};