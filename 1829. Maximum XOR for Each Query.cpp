// Question Link: https://leetcode.com/problems/maximum-xor-for-each-query/description/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>result(n);

        int XOR = 0;
        for(int i=0; i<n; i++){
            XOR ^= nums[i];
        }

        int mask = (pow(2, maximumBit) - 1);

        for(int i=0; i<n; i++){
            int k = XOR ^ mask;
            result[i] = k;

            XOR ^= nums[n-i-1];
        }

        return result;
    }
};
