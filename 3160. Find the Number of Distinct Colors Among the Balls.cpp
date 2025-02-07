//Question Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int>result(n);
        unordered_map<int, int>colorCount;
        unordered_map<int, int>ballColor;

        for(int i=0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballColor.count(ball)){
                int prevColor = ballColor[ball];
                colorCount[prevColor]--;
                if(colorCount[prevColor] == 0) colorCount.erase(prevColor);
            }

            ballColor[ball] = color;
            colorCount[color]++;

            result[i] = colorCount.size();
        }

        return result;
    }
};
