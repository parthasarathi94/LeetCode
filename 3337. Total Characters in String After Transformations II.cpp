//Question Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/

class Solution {
public:
    static const int ALPHA = 26;
    static const long long MOD = 1000000007;
    
    long long trans[31][ALPHA][ALPHA];
    
    int lengthAfterTransformations(string s, long long t, vector<int>& nums) {
        memset(trans, 0, sizeof(trans));
        for(int i = 0; i < ALPHA; i++) {
            for(int d = 1; d <= nums[i]; d++) {
                int j = (i + d) % ALPHA;
                trans[0][i][j] = 1;
            }
        }
        

        for(int k = 0; k < 30; k++) {
            for(int i = 0; i < ALPHA; i++) {
                for(int m = 0; m < ALPHA; m++) if (trans[k][i][m]) {
                    long long v = trans[k][i][m];
                    for(int j = 0; j < ALPHA; j++) {
                        trans[k+1][i][j] = (trans[k+1][i][j] + v * trans[k][m][j]) % MOD;
                    }
                }
            }
        }
        
        vector<long long> cnt(ALPHA, 0);
        for(char c : s) cnt[c - 'a']++;
        
        for(int k = 0; t > 0; k++, t >>= 1) {
            if (t & 1) {
                vector<long long> nextCnt(ALPHA, 0);
                for(int i = 0; i < ALPHA; i++) if (cnt[i]) {
                    long long ci = cnt[i];
                    for(int j = 0; j < ALPHA; j++) {
                        nextCnt[j] = (nextCnt[j] + ci * trans[k][i][j]) % MOD;
                    }
                }
                cnt.swap(nextCnt);
            }
        }
        
        long long ans = 0;
        for(auto x : cnt) ans = (ans + x) % MOD;
        return (int)ans;
    }
};
