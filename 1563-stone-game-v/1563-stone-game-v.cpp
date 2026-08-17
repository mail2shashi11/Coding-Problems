class Solution {
    int memo[501][501];
    int pref[501];

    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;
        for (int k = i; k < j; ++k) {
            int leftSum = pref[k + 1] - pref[i];
            int rightSum = pref[j + 1] - pref[k + 1];

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(i, k));
            } else if (rightSum < leftSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, j));
            } else {
                maxScore = max(maxScore, leftSum + max(solve(i, k), solve(k + 1, j)));
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        return solve(0, n - 1);
    }
};