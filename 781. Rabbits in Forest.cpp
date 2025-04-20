//Question Link: https://leetcode.com/problems/rabbits-in-forest/description/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[answers[i]]++;
        }
        int totalRabbits = 0;
        for(auto& [rabbit, count] : mp){
            int groupSize = rabbit + 1;
            int numGroups = ceil(count/(double)groupSize);
            totalRabbits += numGroups*groupSize;
        }
        return totalRabbits;
    }
};
