//Question Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/

class Solution {
public:

    bool hammingDist(string &s1, string &s2){
        int diff = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                diff++;
            }
            if(diff > 1) return false;
        }

        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int>dp(n, 1);
        vector<int>parentI(n, -1);
        int longestSubseq = 1;
        int longestSubseqIdx = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(groups[j] != groups[i] && words[j].length() == words[i].length() && hammingDist(words[j], words[i])){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parentI[i] = j;

                        if(longestSubseq < dp[i]){
                            longestSubseq = dp[i];
                            longestSubseqIdx = i;
                        }
                    }
                }
            }
        }

        vector<string>result;
        while(longestSubseqIdx != -1){
            result.push_back(words[longestSubseqIdx]);
            longestSubseqIdx = parentI[longestSubseqIdx];
        }

        reverse(begin(result), end(result));
        return result;
    }
};
