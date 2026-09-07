class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<int> endsWith(26, 0);
        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';
            // The number of new distinct subsequences created by appending 'c'
            int added = (total + 1 - endsWith[idx] + MOD) % MOD;
            
            endsWith[idx] = (total + 1) % MOD;
            total = (total + added) % MOD;
        }

        return total;
    }
};