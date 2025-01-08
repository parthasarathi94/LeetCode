//Question Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

// Brute Force

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j = i+1; j< n; j++){
                string str1 = words[i];
                string str2 = words[j];
                if(str1.length() <= str2.length()){
                    if(str2.find(str1) == 0 && str2.rfind(str1) == str2.length()-str1.length()){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
