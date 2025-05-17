//Question Link: https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] > nums[i]){
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};
