class Solution {
public:
    string makeFancyString(string s) {
        int c = 0;
        string ans = "";
        ans += s[0];
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]) c++;
            if(s[i] != s[i-1]) c = 0;
            if(c >= 2) continue;
            ans += s[i];
        }
        return ans;
    }
};