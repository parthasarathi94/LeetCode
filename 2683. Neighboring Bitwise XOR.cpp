// Question Link: https://leetcode.com/problems/neighboring-bitwise-xor/description/

// Optimized Approach

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for(int &x : derived){
            XOR = (XOR ^ x);
        }

        return XOR == 0;
    }
};
