// Question Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/

class Solution {
public:

    unordered_map<int, vector<int>>adj;

    int BFS(int n){
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        visited[0] = true;

        int level = 0;
        while(!q.empty()){
            int m = q.size();
            while(m--){
                int node = q.front();
                q.pop();
                if(node == n-1) return level;

                for(int &neighbour : adj[node]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i=0; i<=n-2; i++){
            adj[i].push_back(i+1);
        }

        vector<int>result;
        for(auto &query : queries){
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v);
            int shortestPath = BFS(n);
            result.push_back(shortestPath);
        }
        return result;
    }
};
