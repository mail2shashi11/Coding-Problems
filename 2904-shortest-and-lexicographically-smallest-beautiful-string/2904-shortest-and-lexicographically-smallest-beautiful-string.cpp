class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        
        if (ones.size() < k) return "";
        
        string ans = "";
        int minLen = INT_MAX;
        
        for (int i = 0; i <= ones.size() - k; ++i) {
            int start = ones[i];
            int end = ones[i + k - 1];
            int len = end - start + 1;
            string sub = s.substr(start, len);
            
            if (len < minLen) {
                minLen = len;
                ans = sub;
            } else if (len == minLen) {
                ans = min(ans, sub);
            }
        }
        
        return ans;
    }
};