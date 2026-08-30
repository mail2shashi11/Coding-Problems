class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mni = 0, mxi = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mni]) mni = i;
            if (nums[i] > nums[mxi]) mxi = i;
        }

        int L = min(mni, mxi);
        int R = max(mni, mxi);

        int option1 = R + 1;             
        int option2 = n - L;             
        int option3 = (L + 1) + (n - R);

        return min({option1, option2, option3});
    }
};