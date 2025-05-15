//Question Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<string>subseq;
        for(int i=0; i<n; i++){
            if(i == 0 || groups[i] != groups[i-1]){
                subseq.push_back(words[i]);
            }
        }
        return subseq;
    }
};
