//Question Link: https://leetcode.com/problems/best-sightseeing-pair/description/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> vec(n, 0);
        vec[0] = values[0] + 0;

        for(int i = 1; i < n; i++) {
            vec[i] = max(values[i]+i, vec[i-1]);
        }

        int result = 0;

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = vec[j-1];
            result = max(result, x+y);
        }

        return result;
    }
};
