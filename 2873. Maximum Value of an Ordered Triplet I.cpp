//Question Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    maxVal = max(maxVal, (long long)(nums[i] - nums[j])*nums[k]);
                }
            }
        }
        return maxVal;
    }
};
