// Question Number - 670 
// Link: https://leetcode.com/problems/maximum-swap/description/
// You are given an integer num. You can swap two digits at most once to get the maximum valued number.
// Return the maximum valued number you can get.
// Example 1:

// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:

// Input: num = 9973
// Output: 9973
// Explanation: No swap.
 

// Constraints:
// 0 <= num <= 10^8


class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int>maxRight(10, -1);

        for(int i=0; i<n; i++){
            int idx = s[i] - '0';
            maxRight[idx] = i;
        }

        for(int i=0; i<n; i++){
            int currDigit = s[i] - '0';

            for(int digit=9; digit>currDigit; digit--){
                if(maxRight[digit] > i){
                    swap(s[i], s[maxRight[digit]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};