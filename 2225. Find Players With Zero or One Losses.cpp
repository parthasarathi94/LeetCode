// Question Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>mp;

        for(int i=0; i<matches.size(); i++){
            int loser = matches[i][1];
            mp[loser]++;
        }

        vector<int>notLost;
        vector<int>lostOnce;

        for(int i=0; i<matches.size(); i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(mp.find(winner) == mp.end()){
                notLost.push_back(winner);
                mp[winner] = 2;
            }

            if(mp[loser] == 1){
                lostOnce.push_back(loser);
            }
        }

        sort(notLost.begin(), notLost.end());
        sort(lostOnce.begin(), lostOnce.end());

        return {notLost, lostOnce};
    }
};
