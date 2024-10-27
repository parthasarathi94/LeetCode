// Question Link: https://leetcode.com/problems/maximal-square/description/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int maxArea = 0;

        vector<vector<int>> t(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (i == 0 || j == 0)
                    t[i][j] = matrix[i][j] - '0';

                else if (matrix[i][j] == '1') {
                    t[i][j] = 1 + min({t[i - 1][j], t[i - 1][j - 1], t[i][j - 1]});
                }
                maxArea = max(maxArea, t[i][j]);
            }
        }

        return maxArea*maxArea;
    }
};
