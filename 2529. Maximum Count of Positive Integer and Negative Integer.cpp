//Question Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countPos = count_if(begin(nums), end(nums), [](int num){
            return num > 0;
        });

        int countNeg = count_if(begin(nums), end(nums), [](int num){
            return num < 0;
        });

        return max(countPos, countNeg);
    }
};
