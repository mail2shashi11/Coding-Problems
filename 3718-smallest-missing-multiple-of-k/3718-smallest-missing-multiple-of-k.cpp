class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp;
        for(int x : nums) mp.insert(x);

        for(int i=k; i<=10000; i+=k){
            if(!mp.count(i)) return i;
        }
        return k;
    }
};