class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int left_sum = 0, right_sum = 0;
        int left_q = 0, right_q = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') left_q++;
            else left_sum += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') right_q++;
            else right_sum += num[i] - '0';
        }

        return (2 * left_sum + 9 * left_q) != (2 * right_sum + 9 * right_q);
    }
};