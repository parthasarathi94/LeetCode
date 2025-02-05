//Question Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n != m) return false;
        
        vector<int>diffCharIdx;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                diffCharIdx.push_back(i);
            }
        }

        if(diffCharIdx.size() > 2) return false;
        if(diffCharIdx.size() == 0) return true;
        if(diffCharIdx.size() == 2){
            int i = diffCharIdx[0];
            int j = diffCharIdx[1];
            return s1[i] == s2[j] && s1[j] == s2[i];
        }

        return false;
    }
};
