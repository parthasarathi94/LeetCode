//Question Link: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i = 1;
        while(i < n-1){
            if(nums[i-1]+nums[i+1] == nums[i]/2.0){
                count++;
            }
            i++;
        }
        return count;
    }
};
