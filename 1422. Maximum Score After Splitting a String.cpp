//Question Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;
        
        int totalOnes = count(begin(s), end(s), '1');

        int zeros = 0;
        int leftOnes = 0;
        for(int i=0; i<=n-2; i++){
            if(s[i] == '0') zeros++;
            else leftOnes++;
            int rightOnes = totalOnes - leftOnes;
            result = max(result, zeros + rightOnes);
        }
        return result;
    }
};
