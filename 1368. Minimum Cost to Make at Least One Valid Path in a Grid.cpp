//Question Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

class Solution {
public:

    vector<vector<int>>dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, 0});

        vector<vector<int>>cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];
            
            for(int dir_i=0; dir_i<=3; dir_i++){
                int new_i = i + dir[dir_i][0];
                int new_j = j + dir[dir_i][1];
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    int gridDir = grid[i][j];
                    int dirCost = (gridDir-1 != dir_i) ? 1 : 0;
                    int newCost = currCost + dirCost;
                    if(newCost < cost[new_i][new_j]){
                        cost[new_i][new_j] = newCost;
                        pq.push({newCost, new_i, new_j});
                    }
                }
            }
        }
        return cost[m-1][n-1];
    }
};
