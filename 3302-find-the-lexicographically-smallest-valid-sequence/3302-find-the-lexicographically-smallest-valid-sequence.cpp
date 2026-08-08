class Solution {
public:
        vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            if (dp[i + 1] < m && word1[i] == word2[m - 1 - dp[i + 1]]) {
                dp[i] = dp[i + 1] + 1;
            }
        }
        
        vector<int> ans;
        bool changed = false;
        int i = 0;
        
        for (int j = 0; j < m; ++j) {
            while (i < n) {
                if (!changed) {
                    if (word1[i] == word2[j]) {
                        ans.push_back(i);
                        i++;
                        break;
                    } else if (dp[i + 1] >= m - 1 - j) {
                        ans.push_back(i);
                        changed = true;
                        i++;
                        break;
                    }
                } else {
                    if (word1[i] == word2[j] && dp[i + 1] >= m - 1 - j) {
                        ans.push_back(i);
                        i++;
                        break;
                    }
                }
                i++;
            }
        }
        
        return ans.size() == m ? ans : vector<int>{};
    }
};