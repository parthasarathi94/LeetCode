// Question Link: https://leetcode.com/problems/trapping-rain-water-ii/description/

class Solution {
public:

    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>>directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>>pq;

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        for(int r=0; r<m; r++){
            for(int c : {0, n-1}){
                pq.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        for(int c=0; c<n; c++){
            for(int r : {0, m-1}){
                pq.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        int waterStored = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int height = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for(vector<int>&dir : directions){
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited[new_i][new_j]){
                    waterStored += max((height - heightMap[new_i][new_j]), 0);

                    pq.push({max(height, heightMap[new_i][new_j]), {new_i, new_j}});
                    visited[new_i][new_j] = true;
                }
            }
        }

        return waterStored;
    }
};
