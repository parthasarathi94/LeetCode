// Question Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        long long result = 0;
        long long currWindowSum = 0;
        unordered_set<int> st;

        while (j < nums.size()) {
            while (st.count(nums[j])) {
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currWindowSum += nums[j];
            st.insert(nums[j]);
            if (j - i + 1 == k) {
                result = max(result, currWindowSum);
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }
        return result;
    }
};
