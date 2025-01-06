//Question Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

// Optimised Solution

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int>answer(n, 0);
        
        int cumVal = 0;
        int cumValSum = 0;

        for(int i=0; i<n; i++){
            answer[i] = cumValSum;
            cumVal += boxes[i] == '0' ? 0 : 1;
            cumValSum += cumVal;
        }

        cumVal = 0;
        cumValSum = 0;

        for(int i=n-1; i>=0; i--){
            answer[i] += cumValSum;
            cumVal += boxes[i] == '0' ? 0 : 1;
            cumValSum += cumVal;
        }

        return answer;
    }
};
