// Question Link: https://leetcode.com/problems/maximum-length-of-pair-chain/description/

// Recursion + Memoization Approach
class Solution {
public:
    
    int n;
    int t[1001][1001];

    int solve(int i, int prev, vector<vector<int>>& pairs){
        if(i >= n) return 0;

        if(prev != -1 && t[i][prev] != -1) return t[i][prev];

        int take = 0;
        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + solve(i+1, i, pairs);
        }
        int skip = solve(i+1, prev, pairs);

        if(prev != -1) t[i][prev] = max(take, skip);
        return max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end());

        memset(t, -1, sizeof(t));

        return solve(0, -1, pairs);
    }
};
