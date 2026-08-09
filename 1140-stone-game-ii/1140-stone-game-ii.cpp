class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<vector<int>> memo(n, vector<int>(n + 1, 0));
        
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        return solve(0, 1, piles, suffixSum, memo);
    }
private:
    int solve(int i, int M, const vector<int>& piles, const vector<int>& suffixSum, vector<vector<int>>& memo) {
        int n = piles.size();
        if (i >= n) return 0;
        
        if (i + 2 * M >= n) return suffixSum[i];
        
        if (memo[i][M] > 0) return memo[i][M];
        
        int maxStones = 0;
        for (int X = 1; X <= 2 * M; ++X) {
            int currentOption = suffixSum[i] - solve(i + X, max(M, X), piles, suffixSum, memo);
            maxStones = max(maxStones, currentOption);
        }
        
        return memo[i][M] = maxStones;
    }
};