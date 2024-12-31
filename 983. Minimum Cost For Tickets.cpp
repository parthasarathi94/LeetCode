//Question Link: https://leetcode.com/problems/minimum-cost-for-tickets/description/

// Recursion + Memoization

class Solution {
public:

    int t[366];

    int solve(int i, int n, vector<int>& days, vector<int>& costs){
        if(i >= n) return 0;

        if(t[i] != -1) return t[i];

        int cost_1 = costs[0] + solve(i+1, n, days, costs);

        int j = i;
        int max_day = days[i] + 7;
        while(j<n && days[j] < max_day){
            j++;
        }
        int cost_7 = costs[1] + solve(j, n, days, costs);

        j = i;
        max_day = days[i] + 30;
        while(j<n && days[j] < max_day){
            j++;
        }
        int cost_30 = costs[2] + solve(j, n, days, costs);

        return t[i] = min({cost_1, cost_7, cost_30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(t, -1, sizeof(t));
        return solve(0, n, days, costs);
    }
};
