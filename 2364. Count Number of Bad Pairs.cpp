//Question Link: https://leetcode.com/problems/count-number-of-bad-pairs/description/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        long long totalPairs = (1LL * n * (n - 1)) / 2;
        long long goodPairs = 0;

        for(int i=0; i<n; i++){
            int diff = nums[i] - i;
            goodPairs += mp[diff];
            mp[diff]++;
        }

        return totalPairs - goodPairs;
    }
};
