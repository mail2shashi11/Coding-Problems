class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return 0;

        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (char c : s) {
            for (int j = n; j >= 1; --j) {
                if (c == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};