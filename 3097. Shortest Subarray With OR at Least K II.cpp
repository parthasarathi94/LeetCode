// Question Link: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/


class Solution {
public:

    void updateWindow(int num, vector<int>&vec, int val){ //1 for adding, -1 for removing
        for(int i=0; i<32; i++){
            if((num >> i) & 1){
                vec[i] += val;
            }
        }
    }

    int getDecimalNumber(vector<int>&vec){
        int num = 0;
        for(int i=0; i<32; i++){
            if(vec[i] > 0){
                num |= (1 << i);
            }
        }
        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>vec(32, 0);
        int result = INT_MAX;
        int i = 0;
        int j = 0;

        while(j < n){
            updateWindow(nums[j], vec, 1);
            while(i <= j && getDecimalNumber(vec) >= k){
                result = min(result, j-i+1);
                updateWindow(nums[i], vec, -1);
                i++;
            }
            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};
