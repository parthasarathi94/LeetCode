//Question Link: https://leetcode.com/problems/count-ways-to-build-good-strings/description/

class Solution {
public:

    const int MOD = 1e9 + 7;
    int t[100001];

    int solve(int length, int low, int high, int zero, int one){
        if(length > high) return 0;

        if(t[length] != -1) return t[length];

        bool addOne = false;
        if(length >= low && length <= high){
            addOne = true;
        }

        int appendOne = solve(length + one, low, high, zero, one);
        int appendZero = solve(length + zero, low, high, zero, one);

        return t[length] = (addOne + appendOne + appendZero) % MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memset(t, -1, sizeof(t));
        return solve(0, low, high, zero, one);
    }
};
