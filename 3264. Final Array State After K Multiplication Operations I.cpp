//Question Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/

class Solution {
public:

    #define P pair<int, int>

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while(k--) {
            pair<int, int> temp = pq.top();
            pq.pop();

            int idx = temp.second;
            int number = temp.first;

            nums[idx] = number*multiplier;

            pq.push({nums[idx], idx});
        }

        return nums;
    }
};
