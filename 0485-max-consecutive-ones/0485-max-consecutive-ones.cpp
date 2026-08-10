class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        int mx = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) c++;
            else{
                mx = max(mx,c);
                c = 0;
            }
        }
        mx = max(mx,c);
        return mx;
    }
};