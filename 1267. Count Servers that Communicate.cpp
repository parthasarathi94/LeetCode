//Question Link: https://leetcode.com/problems/count-servers-that-communicate/description/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>rowServerCount(n, 0);
        vector<int>colServerCount(m, 0);

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 1){
                    rowServerCount[row]++;
                    colServerCount[col]++;
                }
            }
        }

        int resultServer = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 1 && (rowServerCount[row] > 1 || colServerCount[col] > 1)){
                    resultServer++;
                }
            }
        }

        return resultServer;
    }
};
