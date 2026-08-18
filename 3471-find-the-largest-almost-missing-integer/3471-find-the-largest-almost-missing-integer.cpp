class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int mx = -1;
        int mxn = -1;
        for(int x : nums) mp[x]++;
        for(auto it : mp){
            if(it.first > mx && it.second == 1) mx = it.first;
            mxn = max(mxn, it.first);
        }
        if(k == 1) return mx;
        if(k == nums.size()) return mxn;
        int l = -1, r = -1;
        if(mp[nums[0]] == 1) l = nums[0];
        if(mp[nums[nums.size()-1]] == 1) r = nums[nums.size()-1];
        return max(l, r);
    }
};