class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<=n; i++) dp[i][m] = n-i; 
        for(int i=0; i<=m; i++) dp[n][i] = m-i; 

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(a[i] == b[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = 1 + min({dp[i+1][j+1], dp[i][j+1], dp[i+1][j]});
            }
        }
        return dp[0][0];
    }
};