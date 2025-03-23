//Question Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution {
public:

    typedef pair<long long, int> P;
    int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<P, vector<P>, greater<P>>pq;
        vector<long long>result(n, LLONG_MAX);
        vector<int>pathCount(n, 0);
        result[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &temp : adj[currNode]){
                int ngbr = temp.first;
                int time = temp.second;
                if(currTime + time < result[ngbr]){
                    result[ngbr] = currTime + time;
                    pq.push({result[ngbr], ngbr});
                    pathCount[ngbr] = pathCount[currNode];
                }else if(currTime + time == result[ngbr]){
                    pathCount[ngbr] = (pathCount[ngbr] + pathCount[currNode]) % MOD;
                }
            }
        }

        return pathCount[n-1];
    }
};
