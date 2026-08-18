class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int mxi = values[0] + 0;

        for(int j =1; j<values.size(); j++){
            maxScore = max(maxScore, mxi + values[j] - j);
            mxi = max(mxi, values[j]+j);
        }
        return maxScore;
    }
};