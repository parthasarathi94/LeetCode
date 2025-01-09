//Question Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

// Brute Force

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string &word : words){
            if(word.find(pref) == 0) count++;
        }
        return count;
    }
};
