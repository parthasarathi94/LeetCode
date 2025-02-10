//Question Link: https://leetcode.com/problems/clear-digits/description/

class Solution {
public:
    string clearDigits(string s) {
        string result = "";

        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                result.push_back(ch);
            } else if(!result.empty()) {
                result.pop_back();
            }
        }

        return result;
    }
};
