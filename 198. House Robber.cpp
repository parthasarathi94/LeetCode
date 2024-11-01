// Question Link : https://leetcode.com/problems/house-robber/description/

// Botttom Up Approach

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        
        vector<int>t(n+1, 0);
        t[0] = 0;
        t[1] = nums[0];

        for(int i=2; i<=n; i++){
            int stealHouse = nums[i-1] + t[i-2];
            int skipHouse = t[i-1];

            t[i] = max(stealHouse, skipHouse);
        }

        return t[n];
    }
};
