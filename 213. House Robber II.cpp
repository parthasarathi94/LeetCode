// Question Link : https://leetcode.com/problems/house-robber-ii/description/

// Bottom Up Approach

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        
        vector<int>t(n+1, 0);

        t[0] = 0;
        for(int i=1; i<=n-1; i++){
            int stealHouse = nums[i-1] + (i-2 >= 0 ? t[i-2] : 0);
            int skipHouse = t[i-1];
            t[i] = max(stealHouse, skipHouse);
        }
        int result1 = t[n-1];

        t.clear();

        t[0] = 0;
        t[1] = 0;
        for(int i=2; i<=n; i++){
            int stealHouse = nums[i-1] + (i-2 >= 0 ? t[i-2] : 0);
            int skipHouse = t[i-1];
            t[i] = max(stealHouse, skipHouse);
        }
        int result2 = t[n];

        return max(result1, result2);
    }
};
