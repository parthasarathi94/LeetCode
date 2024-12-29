//Question Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

// Bottom Up Approach

class Solution {
public:
   
    const int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();

        vector<vector<long long>>freq(26, vector<long long>(n));
        for(int col=0; col < n; col++){
            for(string& word : words){
                char ch = word[col];
                freq[ch-'a'][col]++;
            }
        }

        vector<vector<int>>t(m+1, vector<int>(n+1, 0));
        t[0][0] = 1;
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(j<n){
                    t[i][j+1] = (t[i][j+1] + t[i][j]) % MOD;
                }
                if(i<m && j<n){
                    t[i+1][j+1] = (t[i+1][j+1] + t[i][j] * freq[target[i]-'a'][j]) % MOD;
                }
            }
        }
        return t[m][n];
    }
};
