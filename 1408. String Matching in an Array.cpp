//Question Link: https://leetcode.com/problems/string-matching-in-an-array/description/

// Brute Force

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string>result;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(words[j].find(words[i]) != string::npos && find(result.begin(), result.end(), words[i]) == result.end()){
                    result.push_back(words[i]);
                }
            }
        }
        return result;
    }
};
