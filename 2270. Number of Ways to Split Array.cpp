//Question Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        long long totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }

        long long leftSum = 0;
        long long rightSum = 0;
        for(int i=0; i<n-1; i++){
            leftSum += nums[i];
            rightSum = totalSum - leftSum;

            if(leftSum >= rightSum) count++;
        }

        return count;
    }
};
