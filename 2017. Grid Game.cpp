//Question Link: https://leetcode.com/problems/grid-game/description/

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainingSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondRowRemaningSum = 0;
        long long minimizeRobot2Points = LLONG_MAX;

        for(int robot1Col=0; robot1Col < grid[0].size(); robot1Col++){
            firstRowRemainingSum -= grid[0][robot1Col];

            long long bestOfRobot2 = max(firstRowRemainingSum, secondRowRemaningSum);

            minimizeRobot2Points = min(minimizeRobot2Points, bestOfRobot2);

            secondRowRemaningSum += grid[1][robot1Col];
        }

        return minimizeRobot2Points;
    }
};
