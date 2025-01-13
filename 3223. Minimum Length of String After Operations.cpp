// Question Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int>freq(26, 0);
        int deletedCharCount = 0;
        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
            if(freq[s[i] - 'a'] == 3){
                freq[s[i] - 'a'] -= 2;
                deletedCharCount += 2;
            }
        }

        return n - deletedCharCount;
    }
};
