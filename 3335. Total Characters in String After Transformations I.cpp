//Question Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/

class Solution {
public:
    int MOD = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        vector<int>mp(26, 0);
        for(char &ch : s){
            mp[ch - 'a']++;
        }

        while(t--){
            vector<int>temp(26, 0);
            for(int i=0; i<26; i++){
                char ch = i + 'a';
                int freq = mp[i];
                if(ch != 'z'){
                    temp[(ch+1)-'a'] = (temp[(ch+1)-'a'] + freq)%MOD;
                }else{
                    temp['a'-'a'] = (temp['a'-'a'] + freq)%MOD;
                    temp['b'-'a'] = (temp['b'-'a'] + freq)%MOD;
                }
            }
            mp = move(temp);
        }
        int length = 0;
        for(int i=0; i<26; i++){
            length = (length + mp[i]) % MOD;
        }
        return length;
    }
};
