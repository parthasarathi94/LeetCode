// Question Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:

    int maxTime = 0;

    void DFS(unordered_map<int, vector<int>>&adj, vector<int>& informTime, int currEmployee, int currTime){
        maxTime = max(maxTime, currTime);

        for(int &employee : adj[currEmployee]){
            DFS(adj, informTime, employee, currTime + informTime[currEmployee]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < manager.size(); i++) {
            int employee_i = i;
            int manager_i = manager[i];

            if (manager_i != -1) {
                adj[manager_i].push_back(employee_i);
            }
        }

        DFS(adj, informTime, headID, 0);

        return maxTime;
    }
};
