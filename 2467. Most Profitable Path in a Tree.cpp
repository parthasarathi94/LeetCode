//Question Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

class Solution {
public:

    unordered_map<int, vector<int>>adj;
    unordered_map<int, int>bobMap;
    int aliceMaxIncome;

    bool bobDFS(int curr, int time, vector<bool>&visited){
        visited[curr] = true;
        bobMap[curr] = time;
        if(curr == 0) return true;

        for(auto &ngbr : adj[curr]){
            if(!visited[ngbr]){
                if(bobDFS(ngbr, time+1, visited) == true) return true;
            }
        }
        
        bobMap.erase(curr);
        return false;
    }

    void aliceDFS(int curr, int time, int aliceIncome, vector<bool>&visited, vector<int>& amount){
        visited[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || time < bobMap[curr]){
            aliceIncome += amount[curr];
        }else if(time == bobMap[curr]){
            aliceIncome += (amount[curr]/2);
        }

        if(adj[curr].size() == 1 && curr != 0) aliceMaxIncome = max(aliceMaxIncome, aliceIncome);
        
        for(auto &ngbr : adj[curr]){
            if(!visited[ngbr]){
                aliceDFS(ngbr, time+1, aliceIncome, visited, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        aliceMaxIncome = INT_MIN;
        for(vector<int>&edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int bobTime = 0;
        vector<bool>visited(n, false);
        bobDFS(bob, bobTime, visited);

        int aliceIncome = 0;
        visited.assign(n, false);
        aliceDFS(0, 0, aliceIncome, visited, amount);

        return aliceMaxIncome;
    }
};
