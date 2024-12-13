//Question Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/

class Solution {
public:
  
    #define P pair<int, int>

    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool>visited(n, false);
        priority_queue<P, vector<P>, greater<P>>pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        long long score = 0;
        while(!pq.empty()){
            P temp = pq.top();
            pq.pop();
            int num = temp.first;
            int index = temp.second;
            if(!visited[index]){
                score += num;
                visited[index] = true;
                if(index-1 >=0 && !visited[index-1]) visited[index-1] = true;
                if(index+1 < n && !visited[index+1]) visited[index+1] = true;
            }
        }
        return score;
    }
};
