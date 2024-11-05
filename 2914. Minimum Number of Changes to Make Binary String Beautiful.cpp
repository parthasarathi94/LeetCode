// Question Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();

        int changes = 0;

        for(int i=0; i<n; i+=2){
            if(s[i] != s[i+1]){
                changes++;
            }
        }

        return changes;
    }
};
