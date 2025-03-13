//Question Link: https://leetcode.com/problems/zero-array-transformation-ii/description/

class Solution {
public:

    int n, Q;

    bool checkDiffArrayTech(vector<int>& nums, vector<vector<int>>& queries, int k){
        vector<int>diff(n, 0);
        for(int i=0; i<=k; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int x = queries[i][2];
            diff[start] += x;
            if(end+1 < n) diff[end+1] -= x;
        }

        int cumSum = 0;
        for(int i=0; i<n; i++){
            cumSum += diff[i];
            diff[i] = cumSum;
            if(nums[i] - diff[i] > 0) return false;
        }

        return true;
    }
  
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        if(all_of(begin(nums), end(nums), [](int x){
            return x == 0;
        })) return 0;

        int l = 0;
        int r = Q-1;
        int k = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(checkDiffArrayTech(nums, queries, mid) == true) {
                k = mid+1;
                r = mid-1;
            } else {
                 l = mid+1;
            }
        }

        return k;
    }
};
