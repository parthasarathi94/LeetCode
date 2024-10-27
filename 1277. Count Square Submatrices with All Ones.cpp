// Question Link : https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

class Solution {
public:

    int r,c;

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&t){
        if(i >= r || j >=c) return 0;

        if(matrix[i][j] == 0) return 0;

        if(t[i][j] != -1) return t[i][j];

        int right = solve(i, j+1, matrix, t);
        int diagonal = solve(i+1, j+1, matrix, t);
        int below = solve(i+1, j, matrix, t);

        return t[i][j] = 1 + min({right, diagonal, below});

    }

    int countSquares(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        int result = 0;

        vector<vector<int>>t(r+1, vector<int>(c+1, -1));

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j] == 1){
                    result += solve(i, j, matrix, t);
                }
            }
        }

        return result;
    }
};


// Time Complexity : O(r*c)
// Space Complexity : O(r*c)
