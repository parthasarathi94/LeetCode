//Question Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num : nums){
            if(num>=10 && num<=99 || num>=1000 && num<=9999 || num == 100000) count++;
        }
        return count;
    }
};
