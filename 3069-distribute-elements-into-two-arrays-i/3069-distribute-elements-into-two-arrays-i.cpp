class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a;
        vector<int> b;
        for(int i=0; i<nums.size(); i++){
            if(i == 0) a.push_back(nums[i]);
            else if(i == 1) b.push_back(nums[i]);
            else{
                if(a.back() > b.back()) a.push_back(nums[i]);
                else b.push_back(nums[i]);
            }
        }
        for(auto& x : b) a.push_back(x);
        return a;
    }
};