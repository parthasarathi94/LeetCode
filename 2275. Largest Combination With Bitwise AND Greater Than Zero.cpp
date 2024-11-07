// Question Link: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;

        for(int i=0; i<24; i++){
            int ithSetBits = 0;
            for(int &num : candidates){
                if((num & (1 << i)) != 0){
                    ithSetBits++;
                }
            }
            result = max(result, ithSetBits);
        }

        return result;
    }
};
