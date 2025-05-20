//Question Link: https://leetcode.com/problems/zero-array-transformation-i/description/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n, 0);
        
        for(auto &query : queries){
            int l = query[0];
            int r = query[1];
            diff[l] += 1;
            if(r+1 < n) diff[r+1] -= 1;
        }

        vector<int>result(n);
        int cumSum = 0;
        for(int i=0; i<n; i++){
            cumSum += diff[i];
            result[i] = cumSum;
        }

        for(int i=0; i<n; i++){
            if(result[i] < nums[i]) return false;
        }

        return true;
    }
};
