//Question Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

class Solution {
public:

    int M = 1e9 + 7;
    vector<string>columnStates;
    vector<vector<int>>t;

    void generateColumnStates(string curr, char prevChar, int l, int m){
        if(l == m){
            columnStates.push_back(curr);
            return;
        }

        for(char ch : {'R', 'G', 'B'}){
            if(ch == prevChar) continue;
            generateColumnStates(curr+ch, ch, l+1, m);
        }
    }

    int solve(int remainingCols, int prevIdx, int m){
        if(remainingCols == 0) return 1;

        if(t[remainingCols][prevIdx] != -1) return t[remainingCols][prevIdx];

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for(int i=0; i<columnStates.size(); i++){
            if(i == prevIdx) continue;
            string currState = columnStates[i];
            bool valid = true;

            for(int j=0; j<m; j++){
                if(prevState[j] == currState[j]){
                    valid = false;
                    break;
                }
            }

            if(valid){
                ways = (ways + solve(remainingCols-1, i, m)) % M;
            }
        }

        return t[remainingCols][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        int result = 0;
        generateColumnStates("", '#', 0, m);

        t = vector<vector<int>>(n+1, vector<int>(columnStates.size()+1, -1));

        for(int i=0; i<columnStates.size(); i++){
            result = (result + solve(n-1, i, m)) % M;
        }

        return result;
    }
};
