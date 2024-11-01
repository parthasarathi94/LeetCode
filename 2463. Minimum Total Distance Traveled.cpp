// Quetion Link: https://leetcode.com/problems/minimum-total-distance-traveled/description/

class Solution {
public:
   
    typedef long long ll;

    ll solve(int robot_i, int pos_i, vector<int>& robot, vector<int>&positions, vector<vector<ll>>&t){
        if(robot_i >= robot.size()) return 0;
        if(pos_i >= positions.size()) return 1e12;

        if(t[robot_i][pos_i] != -1) return t[robot_i][pos_i];

        ll takeCurrFactory = abs(robot[robot_i] - positions[pos_i]) + solve(robot_i+1, pos_i+1, robot, positions, t);

        ll skipCurrFactory = solve(robot_i, pos_i+1, robot, positions, t);

        return t[robot_i][pos_i] = min(takeCurrFactory, skipCurrFactory);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int>positions;
        for(int i=0; i<factory.size(); i++){
            int pos = factory[i][0];
            int limit = factory[i][1];
            for(int j=0; j<limit; j++){
                positions.push_back(pos);
            }
        }

        int m = robot.size();
        int n = positions.size();
        vector<vector<ll>>t(m+1, vector<ll>(n+1, -1));

        return solve(0, 0, robot, positions, t);
    }
};
