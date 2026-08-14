class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cnt(26, 0);
        int mxlen = 0;
        int l = 0;
        for(int r=0; r<s.length(); r++){
            cnt[s[r]- 'a']++;
            while(cnt[s[r] - 'a'] > 2){
                cnt[s[l] - 'a']--;
                l++;
            }
            mxlen = max(mxlen, r-l+1);
        }
        return mxlen;
    }
};