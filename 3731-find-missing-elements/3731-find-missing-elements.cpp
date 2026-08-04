class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int max1 = *max_element(nums.begin(),nums.end());
        int min1 = *min_element(nums.begin(),nums.end());
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=min1; i<=max1; i++){
            if(!s.count(i)) ans.push_back(i);
        }
        return ans;
    }
};