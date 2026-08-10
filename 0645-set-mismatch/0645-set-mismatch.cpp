class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long diff = n*(n+1)/2;
        long long Sqdi = n*(n+1)*(2*n+1)/6;

        for(long long x: nums){
            diff -= x;
            Sqdi -= x*x;
        }
        long long sum = Sqdi/diff;
        int miss = (diff+sum)/2;
        int dup = miss-diff;
        return {dup, miss};
    }
};