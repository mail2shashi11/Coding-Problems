class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int max_valid_len = 0;
        vector<int> pref_count(26, 0);
        for (int i = 0; i < n; ++i) {
            pref_count[target[i] - 'a']++;
            if (pref_count[target[i] - 'a'] <= count[target[i] - 'a']) {
                max_valid_len = i + 1;
            } else {
                break;
            }
        }
        vector<int> cur_count = count;
        for (int k = 0; k < max_valid_len; ++k) {
            cur_count[target[k] - 'a']--;
        }

        for (int i = max_valid_len; i >= 0; --i) {
            if (i < max_valid_len) {
                cur_count[target[i] - 'a']++;
            }
            if (i >= n) continue;

            int target_char = target[i] - 'a';
            int best_char = -1;
            for (int c = target_char + 1; c < 26; ++c) {
                if (cur_count[c] > 0) {
                    best_char = c;
                    break;
                }
            }

            if (best_char != -1) {
                string ans = target.substr(0, i);
                ans += (char)('a' + best_char);
                cur_count[best_char]--;

                for (int c = 0; c < 26; ++c) {
                    while (cur_count[c] > 0) {
                        ans += (char)('a' + c);
                        cur_count[c]--;
                    }
                }
                return ans;
            }
        }

        return "";
    }
};