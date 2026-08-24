class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int st : stones) sum += st;
        int ans = sum;

        for(int i=n-2; i>=1; i--){
            sum -= stones[i+1];
            ans = max(ans, sum - ans);
        }
        return ans;
    }
};