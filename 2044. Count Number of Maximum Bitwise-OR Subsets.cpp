class Solution {
public:

    int countSubsets(int index, int currOR, vector<int>& nums, int maxOR, vector<vector<int>>&t){
        if(index == nums.size()){
            if(currOR == maxOR){
                return 1;
            }
            return 0;
        }

        if(t[index][currOR] != -1) return t[index][currOR];

        int takeCount = countSubsets(index+1, currOR | nums[index], nums, maxOR, t);
        int notTakeCount = countSubsets(index+1, currOR, nums, maxOR, t);

        return t[index][currOR] = takeCount + notTakeCount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxOR = 0;
        for(int &num : nums){
            maxOR |= num;
        }

        vector<vector<int>>t(n+1, vector<int>(maxOR+1, -1));

        int currOR = 0;
        return countSubsets(0, currOR, nums, maxOR, t);
    }
};
