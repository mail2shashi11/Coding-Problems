class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums[i], i};
        }
        
        // Sort pairs by value
        sort(pairs.begin(), pairs.end());
        
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            // Find all elements belonging to the same connected component
            while (j + 1 < n && pairs[j + 1].first - pairs[j].first <= limit) {
                j++;
            }
            
            // Collect and sort original indices of the current component
            vector<int> indices;
            for (int k = i; k <= j; ++k) {
                indices.push_back(pairs[k].second);
            }
            sort(indices.begin(), indices.end());
            
            // Place smallest values into the smallest original positions
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = pairs[i + k].first;
            }
            
            i = j + 1;
        }
        
        return result;
    }
};