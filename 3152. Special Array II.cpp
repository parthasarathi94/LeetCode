//Question Link: https://leetcode.com/problems/special-array-ii/description/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int>count(n);
        count[0] = 0;
        for(int i=1; i<n; i++){
            if(nums[i]%2 == nums[i-1]%2){
                count[i] = count[i-1] + 1;
            }else count[i] = count[i-1];
        }

        vector<bool>result(m, false);
        int i = 0;
        for(auto &query: queries){
            int start = query[0];
            int end = query[1];

            if(count[end] - count[start] == 0){
                result[i] = true;
            }
            i++;
        }
        return result;
    }
};
