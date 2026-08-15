class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int tx = 0;
        bool az = true;
        for(int n : nums){
            tx ^= n;
            if(n != 0) az = false;
        }
        if(az) return 0;
        if(tx != 0) return nums.size();
        return nums.size()-1;
    }
};