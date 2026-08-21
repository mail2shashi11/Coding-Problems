class Solution {
long long count(int idx, int select_count, long long current_lcm, 
                    long long x, const vector<int>& coins) {
        if (idx == coins.size()) {
            if (select_count == 0) return 0;
            return (select_count % 2 == 1 ? 1 : -1) * (x / current_lcm);
        }

        // Option 1: Exclude current coin
        long long res = count(idx + 1, select_count, current_lcm, x, coins);

        // Option 2: Include current coin (with upper-bound pruning)
        long long next_lcm = lcm(current_lcm, (long long)coins[idx]);
        if (next_lcm <= x) {
            res += count(idx + 1, select_count + 1, next_lcm, x, coins);
        }

        return res;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Step 1: Sort and remove redundant multiples
        sort(coins.begin(), coins.end());
        vector<int> filtered;
        for (int c : coins) {
            bool redundant = false;
            for (int f : filtered) {
                if (c % f == 0) { 
                    redundant = true; 
                    break; 
                }
            }
            if (!redundant) filtered.push_back(c);
        }

        // Step 2: Binary search for the k-th smallest amount
        long long low = 1;
        long long high = 1LL * filtered[0] * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(0, 0, 1, mid, filtered) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};