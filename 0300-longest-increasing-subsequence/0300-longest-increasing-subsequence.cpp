class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> srtd(st.begin(), st.end());

        int n = nums.size();
        int m = srtd.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(nums[i] == srtd[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};