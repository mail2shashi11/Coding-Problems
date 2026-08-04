class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int idx = 0;
        for(int i=nums[0]; i<=nums.back(); i++){
            if(i == nums[idx]) idx++;
            else ans.push_back(i);
        }
        return ans;
    }
};