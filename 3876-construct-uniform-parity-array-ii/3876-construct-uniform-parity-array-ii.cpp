class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mno =INT_MAX, mne = INT_MAX;
        bool ho = false, he = false;
        for(int x : nums1){
            if(x%2){
                ho = true;
                mno = min(mno, x);
            }else{
                he = true;
                mne = min(mne, x);
            }
        }
        if(!ho || !he) return true;
        return mno < mne;
    }
};