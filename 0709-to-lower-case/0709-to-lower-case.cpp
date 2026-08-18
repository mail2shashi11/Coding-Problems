class Solution {
public:
    string toLowerCase(string s) {
        //transform(s.begin(), s.end(), s.begin(), ::tolower);
        //for(char &c : s) c = tolower(c);
        for(char &c : s) if (c >= 'A' && c <= 'Z') c += 32;
        return s;
    }
};