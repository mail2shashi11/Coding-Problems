class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0;
        int n = nums.size(), mxlen = 0;
        for(int r=0; r<n; r++){
            mp[nums[r]]++;
            while (mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            mxlen = max(mxlen, r - l + 1);
        }

        return mxlen;
        
    }
};