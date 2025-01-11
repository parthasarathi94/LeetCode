//Question Link: https://leetcode.com/problems/construct-k-palindrome-strings/description/

class Solution {
public:
    bool canConstruct(string s, int k) {

        if(s.length() == k) return true;
        if(s.length() < k) return false;

        vector<int>count(26, 0);
        for(char &ch : s){
            count[ch - 'a']++;
        }

        int oddCount = 0;
        for(int i=0; i<26; i++){
            if(count[i] % 2 != 0) oddCount++;
        }

        return oddCount <= k;
    }
};
