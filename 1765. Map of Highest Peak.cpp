//Question Link: https://leetcode.com/problems/map-of-highest-peak/description/

class Solution {
public:

    typedef pair<int, int> P;
    vector<vector<int>>directions{{0,1}, {1,0}, {0,-1}, {-1,0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        
        vector<vector<int>>heights(r, vector<int>(c, -1));
        queue<P>q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(isWater[i][j] == 1){
                    heights[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int n = q.size();
            while(n--){
                P curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(vector<int>& dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && heights[new_i][new_j] == -1){
                        heights[new_i][new_j] = heights[i][j] + 1;
                        q.push({new_i, new_j});
                    }
                }
            }
        }
        
        return heights;
    }
};
