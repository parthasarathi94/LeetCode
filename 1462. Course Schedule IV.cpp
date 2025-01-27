//Question Link: https://leetcode.com/problems/course-schedule-iv/description/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>>adj;
        vector<int>inDegree(numCourses, 0);
        for(auto &edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (!inDegree[i]) {
                que.push(i);
            }
        }

        unordered_map<int, unordered_set<int>> mp;
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (auto &ngbr : adj[node]) {
                mp[ngbr].insert(node);
                for (auto &prereq : mp[node]) {
                    mp[ngbr].insert(prereq);
                }

                inDegree[ngbr]--;
                if (!inDegree[ngbr]) {
                    que.push(ngbr);
                }
            }
        }

        int Q = queries.size();
        vector<bool> result(Q, false);
        for (int i = 0; i < Q; i++) {
            int src  = queries[i][0];
            int dest = queries[i][1];

            bool isReachable = mp[dest].contains(src);
            result[i] = isReachable;
        }

        return result;

    }
};
