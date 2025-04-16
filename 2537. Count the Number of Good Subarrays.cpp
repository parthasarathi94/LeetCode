//Question Link: https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long result = 0;
        long long pairs = 0;
        unordered_map<int, int>mp;
        while(j < n){
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            while(pairs >= k){
                result += (n-j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }

        return result;
    }
};
