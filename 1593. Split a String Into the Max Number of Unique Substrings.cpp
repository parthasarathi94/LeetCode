// Question Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/



class Solution {
public:

    void solve(string &s, int i, unordered_set<string>&st, int currCount, int &maxCount){
        if(currCount + (s.length()-i) <= maxCount) return;

        if(i >= s.length()){
            maxCount = max(maxCount, currCount);
            return;
        }

        for(int j=i; j<s.length(); j++){
            string subStr = s.substr(i, j-i+1);
            if(st.find(subStr) == st.end()){
                st.insert(subStr);
                solve(s, j+1, st, currCount+1, maxCount);
                st.erase(subStr);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int maxCount = 0;
        int currCount = 0;
        int i = 0;

        solve(s, i, st, currCount, maxCount);

        return maxCount;
    }
};
