//Question Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        vector<pair<int, int>>leftRightIdx(26, {-1, -1});
        for(int i=0; i<n; i++){
            char ch = s[i];
            int index = ch - 'a';
            if(leftRightIdx[index].first == -1){
                leftRightIdx[index].first = i;
            }
            leftRightIdx[index].second = i;
        }

        int result = 0;

        for(int i=0; i<26; i++){
            
            int leftMostIndex = leftRightIdx[i].first;
            int rightMostIndex = leftRightIdx[i].second;

            if(leftMostIndex == -1) continue;

            unordered_set<char>st;
            for(int j=leftMostIndex+1; j<=rightMostIndex-1; j++){
                st.insert(s[j]);
            }

            result += st.size();
        }

        return result;
    }
};
