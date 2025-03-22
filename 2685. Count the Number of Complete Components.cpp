//Question Link: https://leetcode.com/problems/count-the-number-of-complete-components/description/

class Solution {
public:

    void dfs(int i, unordered_map<int, vector<int>>&adj, vector<bool>&visited, int &V, int &E){
        visited[i] = true;
        V++;
        E += adj[i].size();

        for(int &ngbr : adj[i]){
            if(!visited[ngbr]) dfs(ngbr, adj, visited, V, E);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int result = 0;
        vector<bool>visited(n, false);
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            int V = 0;
            int E =0;
            dfs(i, adj, visited, V, E);

            if((V*(V-1)) == E) result++;
        }

        return result;
    }
};
