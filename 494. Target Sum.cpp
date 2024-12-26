//Question Link: https://leetcode.com/problems/target-sum/description/

class Solution {
public:

    int maxSumPossible;
    int n;

    int solve(vector<int>&nums, int i, int currSum, int target, vector<vector<int>>&t){
        if(i == nums.size()){
            if(currSum == target) return 1;
            else return 0;
        }

        if(t[i][currSum + maxSumPossible] != -1) return t[i][currSum + maxSumPossible];

        int plus = solve(nums, i+1, currSum + nums[i], target, t);
        int minus = solve(nums, i+1, currSum - nums[i], target, t);

        return t[i][currSum + maxSumPossible] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        maxSumPossible = accumulate(begin(nums), end(nums), 0);
        n = nums.size();
        vector<vector<int>>t(n+1, vector<int>(2*maxSumPossible + 1, -1));
        return solve(nums, 0, 0, target, t);
    }
};
