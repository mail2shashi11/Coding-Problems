
struct Interval {
    int l, r, weight, id;
};

struct Sol {
    long long weight = 0;
    vector<int> indices;
};

// Priority 1: Maximum weight
// Priority 2: Lexicographically smaller indices array
bool isBetter(const Sol& a, const Sol& b) {
    if (a.weight != b.weight) {
        return a.weight > b.weight;
    }
    return a.indices < b.indices;
}

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals by left endpoint, then right endpoint, then original index
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            return a.id < b.id;
        });

        vector<int> l_times(n);
        for (int i = 0; i < n; ++i) {
            l_times[i] = sorted_intervals[i].l;
        }

        // dp[i][count] stores the optimal choice using at most 'count' intervals from suffix [i...n-1]
        vector<vector<Sol>> dp(n + 1, vector<Sol>(5));

        for (int i = n - 1; i >= 0; --i) {
            // Find the first interval starting after the current interval ends (l > r_i)
            int next_i = upper_bound(l_times.begin(), l_times.end(), sorted_intervals[i].r) - l_times.begin();

            for (int count = 1; count <= 4; ++count) {
                // Option 1: Skip interval i
                Sol best = dp[i + 1][count];

                // Option 2: Take interval i
                Sol take = dp[next_i][count - 1];
                take.weight += sorted_intervals[i].weight;
                take.indices.push_back(sorted_intervals[i].id);
                sort(take.indices.begin(), take.indices.end());

                if (isBetter(take, best)) {
                    best = take;
                }

                dp[i][count] = best;
            }
        }

        return dp[0][4].indices;
    }
};