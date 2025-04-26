//Question Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minPos = -1;
        int maxPos = -1;
        int culpritIdx = -1;

        for(int i=0; i< nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK) culpritIdx = i;
            if(nums[i] == minK) minPos = i;
            if(nums[i] == maxK) maxPos = i;
            long long smaller = min(minPos, maxPos);
            long long temp = smaller - culpritIdx;
            ans += (temp <=0) ? 0 : temp;
        }
        return ans;
    }
};
